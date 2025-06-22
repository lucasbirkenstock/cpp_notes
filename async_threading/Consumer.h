#include <iostream>
#include <memory>
#include <mutex>
#include <queue>

class Consumer
{
    public:
    Consumer(std::shared_ptr<std::mutex> mut, std::shared_ptr<std::queue<int>>);
    void consumeValue();

    private:
    std::shared_ptr<std::mutex> m_mutex;
    std::shared_ptr<std::queue<int>> m_queue;
};