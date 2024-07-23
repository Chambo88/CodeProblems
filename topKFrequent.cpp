#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency_map = {};
        for(const auto& num : nums )
        {
            frequency_map[num]++;
        }  
        vector<vector<int>> bucket{nums.size() + 1};
        for(const auto& kv : frequency_map)
        {
            bucket[kv.second].push_back(kv.first);
        }
        vector<int> results;
        cout << bucket.size() << endl ;
        
        for(int i = nums.size(); i >= 0; i--)
        {
            for(auto& value : bucket[i])
            {
                results.push_back(value);
                if(results.size() == k) return results;
            }
        }
        return results;
    }
};


int main() {
    Solution test_class = Solution();
    vector<int> based = {1,1,1,2,2,3};
    vector<int>  returnee = test_class.topKFrequent(based, 3);
    cout <<" ell ";

    for(auto& group : returnee)
    {
        cout << group << " ";
        cout << endl;
    }
}