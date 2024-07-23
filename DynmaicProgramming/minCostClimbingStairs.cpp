#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = 0;
        int b = cost[n - 1];
        for(int i=n-2; i >= 0; i--) {
            int temp = b;
            b = cost[i] + min(a, b);
            a = b;
        }

        return min(a, b);
    }
};