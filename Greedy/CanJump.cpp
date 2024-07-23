#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;
        if(nums.size() == 1) return true;
        int start = nums[0];
        int i = 0;
        while(i < nums.size() - 1) {
            if(nums[i] == 0) return false;
            int j = i + 1;
            while(j < nums[i] + i) {
                if(j + i >= nums.size() - 1) return true;
                if(nums[j + i] + j > nums[i]) {
                    i += j;
                    break;
                }
                j++;
            }
            i += nums[i];
        }
        return true;
    }
};