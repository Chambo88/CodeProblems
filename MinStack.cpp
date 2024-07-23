#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        normal_stack.push(val);
        if(min_stack.empty() || min_stack.top() > val) min_stack.push(val);
        else min_stack.push(min_stack.top());
    }   
    
    void pop() {
        normal_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return normal_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> min_stack = {};
    stack<int> normal_stack = {};
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    int val = 5;
    MinStack* obj = new MinStack();
    obj->push(val);

    int param_3 = obj->top();
    int param_4 = obj->getMin();
    obj->pop();
    cout << param_3 << " " << param_4 << endl;

    return 0;
}