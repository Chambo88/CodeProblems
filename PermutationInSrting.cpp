#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map{};
        int count = 0;
        for(const auto& c : s1)
        {
            map[c]++;
            count++;
        }
        for(int l=0, r=0; r < s2.size(); r++)
        {
            map[s2[r]] -= 1;
            while (map[s2[r]] < 0)
            {
                map[s2[l]] += 1;
                l++;
                count++;
            }
            count--;
            if (count == 0) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string board = "ab";
    cout << solution.checkInclusion(board, "eidbaooo") << endl;

    return 0;
}