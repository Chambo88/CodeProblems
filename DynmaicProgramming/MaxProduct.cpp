#include <vector>
#include <functional>
#include <climits>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> memoize(nums.size(), vector<int>(nums.size(), INT_MIN));
        int max_product = INT_MIN;
        const function<int(int, int)> dfs = [&](int left, int right) {
            if(left == right) {
                memoize[left][right] = nums[left];
                max_product = max(max_product, nums[left]);
                return memoize[left][right];
            }
            if(memoize[left][right] != INT_MIN) {
                return memoize[left][right];
            }
            dfs(left, right++);
            int total = dfs(left++, right) * nums[left];
            memoize[left][right] = total;
            max_product = max(max_product, total);
            return total;
        };

        dfs(0, nums.size() - 1);
        return max_product;
    }

};