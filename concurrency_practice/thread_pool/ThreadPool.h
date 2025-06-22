#include <functional>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

class ThreadPool
{
    public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();
    void submitTask(std::function<void()> task);

    private:
    std::queue<std::function<void()>> taskQueue;
    std::vector<std::thread> workerThreads;

    std::mutex taskQueueMutex;
    std::condition_variable conditionVar;
    bool stopFlag = false;
};