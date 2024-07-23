#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp{n, vector<int>{m, 0}};
        for(int col=0; col<m; col++) {
            dp[n][col] = 1;
        }

        for(int row=0; row<n; row++) {
            dp[row][m] = 1;
        }

        // 13 8 6 3 1
        // 5 4 3 2 1
        // 1 1 1 1 1


        for(int col=m-1; col>=0; col--) {
            for(int row=n-1; row>= 0;row--) {
                dp[row][col] = dp[row + 1][col] + dp[row][col + 1];
            }
        }

        return dp[0][0];
    }
};

// Input: m = 3, n = 7
// Output: 28