#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums.size() == 0) return false;

        int count = 0;
        int current_index = 0;
        int max_jump = -1;

        while(current_index < nums.size() - 1) {
            int potential_index = current_index + 1;
            int jump_range = nums[current_index];
            int spaces_from_current_index = 1;
            int new_index = 0;
            while(potential_index <= jump_range + current_index) {
                if(potential_index == nums.size() - 1) return count + 1;
                if(max_jump < nums[potential_index] + spaces_from_current_index) {
                    new_index = potential_index;
                    max_jump = nums[potential_index] + spaces_from_current_index;
                }
                spaces_from_current_index++;
                potential_index++;
            }
            current_index = new_index;
            count++;
        }
        return count;
    }
};