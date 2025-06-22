#include <iostream>
#include <future>
#include <chrono>
#include <thread> 
#include "Producer.h"
#include "Consumer.h"

int main() 
{

    auto pQueue = std::make_shared<std::queue<int>>();
    auto mut = std::make_shared<std::mutex>();
    Producer producer(1, 10, pQueue, mut);
    Consumer consumer(mut, pQueue);

    // Create a thread which continually produces values
    std::thread producerThread([&producer]() {
        while (true)
        {
            producer.produceRandNum();
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    });

    // Create a thread which is constantly consuming values
    std::thread consumerThread([&consumer](){
        while (true)
        {
            consumer.consumeValue();
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    });

    producerThread.join();
    consumerThread.join();
    return 1;
}

