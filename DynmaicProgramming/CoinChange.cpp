#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Filter out coins that are INT_MAX
        vector<int> valid_coins;
        for (int coin : coins) {
            if (coin != INT_MAX) {
                valid_coins.push_back(coin);
            }
        }

        // Initialize the DP array with a large value (amount + 1, which is greater than any possible answer)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: 0 coins to make amount 0

        // Iterate over all the coins
        for (int coin : valid_coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        // If dp[amount] is still amount + 1, it means it's not possible to form the amount
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

