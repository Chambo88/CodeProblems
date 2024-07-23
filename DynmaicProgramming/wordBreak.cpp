#include <string>
#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictTwo(wordDict.begin(), wordDict.end());
        vector<vector<int>> memoize(s.size(), vector<int>(s.size(), -1));


        const function<bool(int, int)> helper = [&](int left, int right) {
            if(left >= s.size()) return true;
            bool ans = false;
            while(right < s.size()) {
                if(memoize[left][right] != -1) {
                    if(memoize[left][right] == 1) {
                        ans = helper(right + 1, right + 1);
                    }
                } else {
                    string eval = s.substr(left, right - left + 1);
                    if(wordDictTwo.find(eval) != wordDictTwo.cend()) {
                        memoize[left][right] = 1;
                        ans = helper(right + 1, right + 1);
                    } else {
                        memoize[left][right] = 0;
                    }
                }
                if(ans) return ans;
                right++;
            }
            return false;
        };

        return helper(0, 0);
    }
};