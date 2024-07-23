#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans{};

        for(int i=0; i<heights.size(); i++) {
            for(int j=0; j<heights[0].size(); j++) {
                if(evaluate(i, j, heights)) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }

    bool evaluate(int x, int y, vector<vector<int>> heights_copy) {
        stack<pair<int, int>> stk{};
        pair<int, int> current;
        stk.push({x, y});

        bool atlantic = false;
        bool pacific = false;

        while(!stk.empty()) {
            current = stk.top();
            stk.pop();
            int x = current.first;
            int y = current.second;
            heights_copy[x][y] = -1;

            // have we reached an edge?
            if(x == 0 || y ==0) {
                pacific = true;
            }
            if(x == heights_copy.size() - 1 ||
                y == heights_copy[0].size() - 1) {
                atlantic = true;
            }
            if (pacific && atlantic) return true;

            if(x > 0 && heights_copy[x-1][y] != -1 && 
                heights_copy[x-1][y] <= heights_copy[x][y]
            ) {
                stk.push({x-1, y});
            }
            if(y > 0 && heights_copy[x][y-1] != -1 && 
                heights_copy[x][y-1] <= heights_copy[x][y]
            ) {
                stk.push({x, y-1});
            }
            if(x < heights_copy.size() - 1  && 
                heights_copy[x+1][y] != -1 && 
                heights_copy[x+1][y] <= heights_copy[x][y]
            ) {
                stk.push({x+1, y});
            }
            if(y < heights_copy[0].size() - 1 &&
                heights_copy[x][y+1] != -1 && 
                heights_copy[x][y+1] <= heights_copy[x][y]
            ) {
                stk.push({x, y+1});
            }
        }

        return false;
    }
};