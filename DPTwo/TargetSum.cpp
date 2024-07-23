#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map{};

        const function<int(int, int)> dfs = [&](int it, int amount) {
            if(it == nums.size() - 1) return (amount == 0)? 1 : 0;
            if(map[amount].size() > 0) {
                if(map[amount][it] != -1) return map[amount][it];
            }

            int total_if_add = dfs(it+1, amount + nums[it]);
            int total_if_minus = dfs(it+1, amount - nums[it]);

            if(map[amount].size() == 0) {
                map[amount] = vector<int>(nums.size()-1, -1);
            }
            map[amount][it] = total_if_add + total_if_minus;
            return map[amount][it];
        };

        return dfs(0, target);        
    }
};