#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap = {};
        for(int i=0; i < nums.size(); i++) 
        {
            if (hashMap.find(target - nums[i]) == hashMap.cend()) 
            {
                hashMap[nums[i]] = i;
            }
            else return {hashMap[target - nums[i]], i};

        }
        return {0,0};
    }
};

int main() {
    Solution test_class = Solution();
    vector<int> based = {3,4,5,6};
    test_class.twoSum(based , 7);
}