#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    auto now = chrono::system_clock::now().time_since_epoch();
    cout<< now.count()<<endl;
    return 0;
}