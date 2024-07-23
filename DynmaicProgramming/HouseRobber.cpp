#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int goods_robbed_last = 0;
        int goods_robbed_second = 0;
        int goods_robbed_third = nums[n-1];

        for(int i=n-2; i>=0; i++) {
            int temp2 = goods_robbed_second;
            int temp3 = goods_robbed_third;

            goods_robbed_third = nums[n-2] + max(goods_robbed_second, goods_robbed_last);
            goods_robbed_second = temp3;
            goods_robbed_last = temp2;
        }

        return max(goods_robbed_third, goods_robbed_second);
    }
};