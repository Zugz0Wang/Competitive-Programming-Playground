/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include <stack>
using namespace std;
// @lc code=start
class MyQueue {
public:
    MyQueue() { // Imagine two head to head stack. If pushing, move all item to the pushing stack, pop otherwise.
        
    }
    
    void push(int x) {
        if (!is_push_state_) {
            for (int i = 0; i < size_; i++) {
                push_stack_.push(pop_stack_.top());
                pop_stack_.pop();
            }
            is_push_state_ = true;
        } 
        size_++;
        push_stack_.push(x);
    }
    
    int pop() {
        if (is_push_state_) {
            for (int i = 0; i < size_; i++) {
                pop_stack_.push(push_stack_.top());
                push_stack_.pop();
            }
            is_push_state_ = false;
        }
        size_--;
        int to_return = pop_stack_.top();
        pop_stack_.pop();
        return to_return;
    }
    
    int peek() {
        if (is_push_state_) {
            for (int i = 0; i < size_; i++) {
                pop_stack_.push(push_stack_.top());
                push_stack_.pop();
            }
            is_push_state_ = false;
        }
        
        return pop_stack_.top();;
    }
    
    bool empty() {
        return size_ == 0;
    }
private:
    int size_ = 0;
    bool is_push_state_ = false;
    stack<int> push_stack_;
    stack<int> pop_stack_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

