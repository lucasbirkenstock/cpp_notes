#include "Consumer.h"

Consumer::Consumer(std::shared_ptr<std::mutex> mut, std::shared_ptr<std::queue<int>> queue)
: m_mutex(mut), 
  m_queue(queue)
{   
    std::cout << "Created consumer" << std::endl;
};

// Simply read and print value as an example of consumption
void Consumer::consumeValue()
{
    // Check if mutex and queue are valid

    if (m_mutex && m_queue)
    {
        std::cout << "Consumer attempting to acquire the mutex lock" << std::endl;
        std::lock_guard<std::mutex> lock(*m_mutex); // blocks/only proceeds once the lock is acquired
        std::cout << "Consumer has acquired the mutex lock" << std::endl;

        if (!m_queue->empty())
        {
            std::cout << "Reading value from queue: " << m_queue->front() << std::endl;
            m_queue->pop();
        }
        
    }
    std::cout << "Consumer's lock_guard is going out of scope, releasing lock" << std::endl;
};