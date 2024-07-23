#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        const int max_zero = robHelper(nums, 0, nums.size() - 2);
        const int max_one = robHelper(nums, 1, nums.size() - 1);
        // const int max_two = robHelper(nums, 1, nums.size() - 1);


        return max(max_zero, max_one);
    }

    const int robHelper(const vector<int>& nums, int start, int end) const {
        int n = end;
        int goods_robbed_last = 0;
        int goods_robbed_second = 0;
        int goods_robbed_third = nums[n-1];

        for(int i=end; i>=start; i++) {
            int temp2 = goods_robbed_second;
            int temp3 = goods_robbed_third;

            goods_robbed_third = nums[n-2] + max(goods_robbed_second, goods_robbed_last);
            goods_robbed_second = temp3;
            goods_robbed_last = temp2;
        }

        return max(goods_robbed_third, goods_robbed_second);
    }
};