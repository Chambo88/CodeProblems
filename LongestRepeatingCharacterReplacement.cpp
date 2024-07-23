#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map = {};
        int max_substring = 0;
        int maxf = 0;
        for (int r=0,l=0; r < s.size() ; r++)
        {
            map[s[r]] += 1;
            maxf = max(maxf, map[s[r]]);
            if (r - l + 1 - maxf > k )
            {
                map[s[l]] -= 1;
                l++;
            }
            else
            {
                max_substring = max(max_substring, r - l + 1);
            }
        }
        return max_substring;
    }

};

int main() {
Solution solution;
    string board = "AABA";
    cout << solution.characterReplacement(board, 0) << endl;

    return 0;
}