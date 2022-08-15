/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        _q.push(x);
        size_++;
    }
    
    int pop() {
        for (int i = 0; i < size_-1; i++) {
            _q.push(_q.front());
            _q.pop();
        } // A cycle, the tail is now at the head
        size_--;
        int to_return = _q.front();
        _q.pop();
        return to_return;
    }
    
    int top() {
        return _q.back();
    }
    
    bool empty() {
        return size_ == 0;
    }
private:
    int size_ = 0;
    queue<int> _q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

