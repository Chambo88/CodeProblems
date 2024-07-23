#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        unordered_map<char, int> map{};
        int count = s2.size();
        string ans = "";
        pair<int, int> values = {0, INT_MAX};
        bool found = false;
        for(const auto& c : s2)
        {
            map[c]++;
        }
        for(int l=0, r=0; r < s1.size(); r++)
        {
            if (map.find(s1[r]) != map.cend())
            {
                map[s1[r]] -= 1;
                if (map[s1[r]] >= 0) count--;
                while (count == 0)
                {
                    found = true;
                    cout << l << " - left, right - " << r << endl;
                    if (r - l + 1 < values.second - values.first + 1)
                    {
                        cout << l << " setting new valyes ^ " << r << endl;
                        values = {l, r};
                    }
                    if (map.find(s1[l]) != map.cend())
                    {
                        map[s1[l]]++;
                        if (map[s1[l]] > 0)
                        {
                            count++;
                        }
                    }
                    l++;
                }
            }
        }
        if (found) return std::string(s1.c_str() + values.first, s1.c_str() + values.second + 1);
        return "";
    }
};

int main() {
    Solution solution;
    string board = "a";
    cout << solution.minWindow("a", "a") << endl;

    return 0;
}