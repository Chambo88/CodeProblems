#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counter = {};
        for(const char& a : s)
        {
            if (counter.find(a) != counter.cend()) counter[a]++;
            else {counter[a] = 1;};
            cout << a << counter[a] << endl;
        }

        for(const char& a : t)
        {
            if (counter.find(a) != counter.cend()) counter[a]--;
            else return false;
            cout << a << counter[a] << endl;
        }
        

        for(const auto& count : counter)
        {
            if (count.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution test_class = Solution();
    test_class.isAnagram("Car", "rat");
}