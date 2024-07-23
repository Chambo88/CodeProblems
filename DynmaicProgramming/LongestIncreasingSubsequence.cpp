#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> max_array(nums.size() + 1, 1);
        int global_max = 1;

        for(int i=nums.size()-2; i>=0; i--) {
            int potential_max = 1;
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j] > nums[i]) {
                    potential_max = max(potential_max, max_array[j] + 1);
                }
            }
            max_array[i] = potential_max;
            global_max = max(potential_max, global_max);
        }

        return global_max;
    }
};