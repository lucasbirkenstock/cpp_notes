#include "Producer.h"
#include <iostream>

Producer::Producer(int min, int max, std::shared_ptr<std::queue<int>> p_queue, std::shared_ptr<std::mutex> mut)
:   m_distribution(min,max),
    m_pQueue(p_queue),
    m_mutex(mut)
{
    std::cout << "Created producer object" << std::endl;
}

void Producer::produceRandNum()
{
    const auto randNum{m_distribution(m_numGenerator)};

    // Check if shared pointers are valid
    if (m_mutex && m_pQueue)
    {
        // Attempt to acquire lock. Block (do not run) until it is acquired. 
        std::cout << "Producer attempting to acquire lock" << std::endl;
        std::lock_guard<std::mutex> lock(*m_mutex); // dereferencing the shared pointer (m_mutex) always yields a reference, which lock_gard expects
        std::cout << "Producer has acquired the mutex lock" << std::endl;

        // Push value to shared queue
        m_pQueue->push(randNum);
    }
    
    std::cout << "Producer's lock_guard has gone out of scope, releasing the lock." << std::endl;
}