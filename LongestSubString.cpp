#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen = {};
        queue<char> recent = {};
        int potential_max = 0;
        for (const char& c : s)
        {
            if (seen.find(c) == seen.cend())
            {
                seen.insert(c);
                recent.push(c);
            }
            else
            {
                potential_max = max(potential_max, (int)seen.size());
                while (recent.front() != c)
                {

                    seen.erase(recent.front());
                    recent.pop();
                }
                recent.pop();
                recent.push(c);
            }
        }
        return max(potential_max, (int)seen.size());
    }
};

int main() {
Solution solution;
    string board = "pwwkew";
    cout << solution.lengthOfLongestSubstring(board) << endl;

    return 0;
}