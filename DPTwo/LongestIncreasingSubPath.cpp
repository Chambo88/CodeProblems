#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memoize(matrix.size(), vector<int>(matrix[0].size(), -1));
        vector<pair<int, int>> directions = {{0,-1}, {0,1}, {1,0}, {-1,0}};
        int result = 0;


        const function<int(int, int)> dfs = [&](int row, int col) {
            if(memoize[row][col] != -1) {
                return memoize[row][col];
            }
            int max_value = 1;
            for(const auto& [dRow, dCol] : directions) {
                // out of bounds?
                if(row + dRow >= 0 && row + dRow < matrix.size() &&
                    col + dCol >= 0 && col + dCol < matrix[0].size()) {
                        if(matrix[row + dRow][col + dCol] > matrix[row][col]) {
                            int longest_sub_path = dfs(dRow, dCol) + 1;
                            max_value = max(max_value, longest_sub_path);
                        }
                }
            }

            memoize[row][col] = max_value;
            return max_value;
        };

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                result = max(result, dfs(i, j));
            }
        }
        return result; 
    }
};