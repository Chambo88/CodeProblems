#include <unordered_map>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> memoize(s1.size(), vector<int>(s2.size(), -1));

        const function<bool(int, int, int)> dfs = [&](int it1, int it2, int it3) {
            if(it3 == s3.size()) return true;
            if(memoize[it1][it2] != -1) return (bool)memoize[it1][it2];

            if(it1 == s1.size() && s2[it2] == s3[it3]) return dfs(it1, it2+1, it3+1);
            else return false;
        };

        dfs(0, 0, 0);
    }
};