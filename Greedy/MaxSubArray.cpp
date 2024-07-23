#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = nums[0];
        int current_sub = (nums[0] < 0)? 0 : nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(current_sub + nums[i] > 0) {
                current_sub += nums[i];
                max_sub = max(max_sub, current_sub);
            } else {
                max_sub = max(max_sub, nums[i]);
                current_sub = 0;
            }
        }
        return max_sub;
    }
};
//Input: nums = [2,-3,4,-2,2,1,-1,4]

//Output: 8