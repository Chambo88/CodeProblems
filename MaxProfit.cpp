#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int current_min = INT_MAX;
        for (int i=0; i<prices.size(); i++)
        {
            if (prices[i] < current_min)
            {
                current_min = prices[i];
            }
            if (prices[i] > current_min)
            {
                max_profit = max(prices[i] - current_min, max_profit);
            }
        }
        return max_profit;
    }
};

int main() {
Solution solution;
    vector<int> board = {1};
    cout << solution.maxProfit(board) << endl;

    return 0;
}