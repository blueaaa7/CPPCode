#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>

std::mutex mtx;
std::condition_variable cv;
bool ready;

void producer()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "producer is already" << std::endl;
    }
    cv.notify_all();
}

void consumer(int threadId)
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock,[](){
        return ready;
    });
    std::cout << "consumer "<<threadId<<"is already" << std::endl;
}

int main()
{
    std::vector<std::thread> producerThreads;
    std::vector<std::thread> consumerThreads;

    for(int i = 0; i < 3; i++)
    {
        producerThreads.emplace_back(producer);
    }

    for(int i = 0; i < 5; i++)
    {
        consumerThreads.emplace_back(std::bind(consumer,i));
    }

    for(auto &t : producerThreads)
    {
        t.join();
    }   

    for(auto &t : consumerThreads)
    {
        t.join();
    }

    return 0;
}