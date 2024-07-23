#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk = {};
        unordered_map<char, char> lookup = {
            {'}' , '{'},
            {')' , '('},
            {']' , '['},
        };
        for(const auto& c : s)
        {
            if (c == '{' || c =='(' || c == '[')
            {
                stk.push(c);
            } else
            {
                if (not empty && stk.top() != lookup[c]) return false;
                stk.pop();
            }
        }
        if (stk.size()) return true;
        return false;
    }
};


int main() {
Solution solution;
    vector<int> board = {0,2,0,3,1,0,1,3,2,1
    };

    cout << solution.trap(board) << endl;

    return 0;
}