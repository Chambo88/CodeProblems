#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) const {
        int ans = 0;

        function<void(int, int)> helper = [&](int x, int y) {
            if(x < 0 ||
                y < 0 ||
                x == grid.size() ||
                y == grid[0].size() ||
                grid[x][y] == '#' ||
                grid[x][y] == '0')
            {
                return;
            }
            grid[x][y] = '#';
            helper(x + 1 , y);
            helper(x - 1, y);
            helper(x, y + 1);
            helper(x, y - 1);
            return;
        };

        for(int x=0; x < grid.size(); x++) {
            for(int y=0; y < grid[0].size(); y++) {
                if(grid[x][y] == '1'){
                    ans += 1;
                    helper(x, y);}
            }
        }
        
        return ans;
    }
};


// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]