#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results = {};
        vector<stack<string>> stcks = {};
        return recurse_me("", {}, n);
    }

    vector<string> recurse_me(string s, stack<string> stk, int n)
    {
        if (s.size() + stk.size()  == n* 2)
        {
            while(!stk.empty())
            {
                s += stk.top();
                stk.pop();
            }
            return vector{s};
        }
        else
        {
            if (stk.empty())
            {
                stack<string> copy_stk = {stk};
                copy_stk.push(")");
                return recurse_me(s + "(" ,copy_stk, n);
            }
            else
            {
                stack<string> copy_stk = {stk};
                copy_stk.push(")");
                stk.pop();
                vector<string> vec1 = recurse_me(s + ")", stk, n);
                vector<string> vec2 = recurse_me(s + "(", copy_stk, n);
                std::vector<std::string> combinedVec(vec1.begin(), vec1.end());
                combinedVec.insert(combinedVec.end(), vec2.begin(), vec2.end());
                return combinedVec;
            }
        }
    }
};


int main() {
Solution solution;
    vector<int> board = {0,2,0,3,1,0,1,3,2,1
    };

    cout << solution.trap(board) << endl;

    return 0;
}