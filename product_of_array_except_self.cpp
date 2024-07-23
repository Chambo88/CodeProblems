#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> nums_copy = vector(nums);
        unordered_map<int, int> prefix = {};
        unordered_map<int, int> suffix = {};
        int prefix_total = 1;
        for(int i=0; i < nums.size() - 1; i++)
        {
            prefix_total *= nums[i];
            prefix[i] = prefix_total;
        }
        int suffix_total = 1;
        for(int i=nums.size() - 1; i > 0; i--)
        {
            suffix_total *= nums[i];
            suffix[i] = suffix_total;
        }
        vector<int> result = {};
        for(int i=0; i < nums.size(); i++)
        {
            int first = 1;
            int last = 1; 
            if (i > 0)
            {
                first = prefix[i - 1];
            }
            if (i < nums.size() - 1)
            {
                last = suffix[i + 1];
            }
            result.push_back(first * last);
        }
        return result;
    }
};

int main() {
    Solution test_class = Solution();
    vector<int> based = {1,1,1,2,2,3};
    vector<int>  returnee = test_class.productExceptSelf(based);

    for(auto& group : returnee)
    {
        cout << group << endl;
    }
}