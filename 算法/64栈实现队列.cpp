#include <stack>
#include <deque>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        dque.push_back(x);
    }
    
    int pop() {
        int tmp = dque.front();
        dque.pop_front();
        return tmp;
    }
    
    int peek() {
        return dque.front();
    }
    
    bool empty() {
        return dque.empty();
    }
private:
    deque<int> dque ;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */