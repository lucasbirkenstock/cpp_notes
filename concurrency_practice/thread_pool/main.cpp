#include "ThreadPool.h"
#include <thread>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

int main()
{
    // RNG
    std::default_random_engine numGenerator;
    std::uniform_int_distribution<int> distribution(1000, 5000);

    // Create a thread pool with 4 threads
    ThreadPool pool(4);


    while (true)
    {
        // Enqueue tasks for execution
        for (int i = 0; i < 5; ++i) 
        {
            pool.submitTask([i, numGenerator, distribution]() mutable
            {
                std::cout << "Task " << i << " is running on thread " << std::this_thread::get_id() << std::endl;

                // Simulate some work
                auto randNum{distribution(numGenerator)};
                std::this_thread::sleep_for(std::chrono::milliseconds(randNum));
            });
        }
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}