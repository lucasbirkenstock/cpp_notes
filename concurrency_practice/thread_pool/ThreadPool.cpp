#include "ThreadPool.h"

/*
Notes:

Each lambda body emplaced back into the vector of threads has an infinite while loop. 
Because the lambda is implicitly converted to an std::thread by the emplace_back function (workerThreads takes std::thread, so it's converted),
the infinite loop is run in the new thread created. The main thread creates numThreads number of threads without the main thread running the infinite loops.  
The infinite loops are run in the new threads. 



*/

ThreadPool::ThreadPool(size_t numThreads)
{
    for (size_t i = 0; i < numThreads; ++i)
    {
        // use emplace_back because threads are non copyable, construct thread in place in the vector.
        // Capture "this" in lambda in order to access threadpool's own members
        // Lambda object used as emplace_back's argument is implititly converted to an std::thread. 
        workerThreads.emplace_back([this]()
        { // lambda body
            while (true)
            {
                std::function<void()> aTask{};

                // Lock scope: create code block for the mutex so that it is released when the block is exited
                {
                    // Use a unique_lock over a lock_guard. condition_variable requires this. 
                    std::unique_lock<std::mutex> theLock(taskQueueMutex);
                    
                    // Blocks until thread is awakened by the condition variable. Only after being awakened is the mutex acquired and return (stopFlag || !taskQueue.empty()); evaluated.
                    conditionVar.wait(theLock, [this]()
                    {
                        // Wait until the stop flag is set to true, or there is an available task in the queue. 
                        return (stopFlag || !taskQueue.empty());
                    });


                    // Exit the thread if the stop flag is set to true and there are no remaining tasks in the queue
                    if (stopFlag && taskQueue.empty())
                    {
                        return;
                    }

                    // Acquire the next task from the queue, remove it from the queue
                    aTask = std::move(taskQueue.front());
                    taskQueue.pop();
                }

                // Execute the task from outside the lock
                aTask();
            }
        }); // lambda body
    }
}


ThreadPool::~ThreadPool()
{
    // Lock queue to update the stop flag
    std::unique_lock<std::mutex> lock(taskQueueMutex);
    stopFlag = true;

    // Wake up all threads so that conditionVar.wait(theLock, [this]()... evaluates.
    conditionVar.notify_all();

    // Block main thread until each of the threads in the pool complete their tasks
    // Join is called one by one, but the rest are still running concurrently. 
    for (auto& thread : workerThreads)
    {
        thread.join();
    }
}

void ThreadPool::submitTask(std::function<void()> task)
{
    {
        // Acquire lock
        std::unique_lock<std::mutex> lock(taskQueueMutex);
        taskQueue.emplace(std::move(task));
    }
    // Release lock as it goes out of scope

    // Notify one thread of the new task
    conditionVar.notify_one();
}