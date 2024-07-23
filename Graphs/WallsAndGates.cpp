#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q{};
        pair<int, int> current;

        for(int i=0; i < grid.size(); i++) {
            for(int j=0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) q.emplace(i, j);
            }
        }

        while(!q.empty()) {
            current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            if(x > 0 && grid[x - 1][y] == INT_MAX) {
                grid[x-1][y] = grid[x][y] + 1;
                q.emplace(x-1, y);
            }
            if(y > 0 && grid[x][y-1] == INT_MAX) {
                grid[x][y-1] = grid[x][y] + 1;
                q.emplace(x, y-1);
            }
            if(x < grid.size() - 1 && grid[x + 1][y] == INT_MAX) {
                grid[x+1][y] = grid[x][y] + 1;
                q.emplace(x+1, y);
            }
            if(y < grid[0].size() - 1 && grid[x][y + 1]== INT_MAX) {
                grid[x][y+1] = grid[x][y] + 1;
                q.emplace(x, y+1);
            }
        }


    }
};
