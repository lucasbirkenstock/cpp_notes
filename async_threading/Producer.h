#include <random>
#include <memory>
#include <queue>
#include <mutex> 

class Producer
{
    public:

    Producer(int min, int max, std::shared_ptr<std::queue<int>> p_queue, std::shared_ptr<std::mutex> mut);
    void produceRandNum();

    private:
    std::default_random_engine m_numGenerator;
    std::uniform_int_distribution<int> m_distribution;
    std::shared_ptr<std::queue<int>> m_pQueue;
    std::shared_ptr<std::mutex> m_mutex;
};