#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q{};
        int count = 0;
        pair<int, int> current;

        for(int i=0; i < grid.size(); i++) {
            for(int j=0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.emplace(i, j);
            }
        }

        while(!q.empty()) {
            int q_length = q.size();
            for(int i=0; i < q_length; i++) {
                current = q.front();
                q.pop();
                int x = current.first;
                int y = current.second;
                if(x > 0 && grid[x - 1][y] == 1) {
                    grid[x-1][y] = 2;
                    q.emplace(x-1, y);
                }
                if(y > 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    q.emplace(x, y-1);
                }
                if(x < grid.size() - 1 && grid[x + 1][y] == 1) {
                    grid[x+1][y] = 2;
                    q.emplace(x+1, y);
                }
                if(y < grid[0].size() - 1 && grid[x][y + 1] == 1) {
                    grid[x][y+1] = 2;
                    q.emplace(x, y+1);
                }
            }
            count += 1;
        }


        for(int i=0; i<grid.size(); i++) {
            for(int j=0;j<grid[0].size(); j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return count;
    }
};