#include <iostream>
#include <mutex>
#include <thread>
#include <functional>

std::mutex mtx;

int sharedInt = 1;

void function1(int threadId)
{
    for(int i = 0; i < 10; i++)
    {
        mtx.lock();
        std::cout<<"threadID="<<threadId<<std::endl;
        // mtx.unlock();
    }
}

int main()
{
    std::thread threads[5];
    for(int i = 0; i < 5; i++)
    {
        threads[i] = std::thread(std::bind(function1,i));
    }
    for(int i = 0;i < 5;i++)
    {
        threads[i].join();
    }
    return 0;
}