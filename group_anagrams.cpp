#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#VERY BAD

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups = {};
        unordered_map<int, unordered_map<char, int>> counts = {};
        for(auto& str : strs)
        {
            unordered_map<char, int> disect = {};
            for(const char a : str)
            {
                disect[a]++;
            }
            bool add = true;
            for(auto& count_map : counts)
            {
                if (are_anagrams(count_map.second, disect))
                {

                    groups[count_map.first].push_back(str);
                    add = false;
                    break;
                }
            }
            if(add) {
                counts[counts.size()] = disect;
                groups.push_back({str});
            }

        }
        return groups;
    }

private:
    bool are_anagrams(unordered_map<char, int> a, unordered_map<char, int> b)
    {
        for(auto& b_key_values : b)
        {

            if(a.find(b_key_values.first) == a.cend()) return false;
            a[b_key_values.first] -= b_key_values.second;
        }
        for(auto& a_kv : a)
        {
            if (a_kv.second != 0) return false;
        }
        return true;
    }
};
int main() {
    Solution test_class = Solution();
    vector<string> based = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> returnee = test_class.groupAnagrams(based);
    for(auto& group : returnee)
    {
        for (auto& g : group)
        {
            cout << g << " ";
        }
        cout << endl;
    }
}