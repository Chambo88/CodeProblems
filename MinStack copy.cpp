#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <string>


using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values = {};
        unordered_set<string> operands = {"*", "/", "+", "-"};
        for (const string& s : tokens)
        {
            if(operands.find(s) == operands.cend())
            {
                values.push(stoi(s));
            }
            else
            {
                int value_2 = values.top();
                values.pop();
                int value_1 = values.top();
                values.pop();
                if(s == "+"){values.push(value_1+value_2);}
                if(s == "-"){values.push(value_1-value_2);}
                if(s == "*"){values.push(value_1*value_2);}
                if(s == "/"){values.push(value_1/value_2);}
            }
        }
        return values.top();
    }
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