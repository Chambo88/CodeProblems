#include <vector>
#include <unordered_set>
#include <functional>
#include <stack>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> seen = {};
        vector<vector<int>> connected(n, vector<int>{});
        stack<int> stk{};
        for(auto& edge : edges) {
            connected[edge[0]].push_back(edge[1]);
            connected[edge[1]].push_back(edge[0]);
        }
        int leaf = -1;
        for(int i=0; i<n; i++) {
            if(connected[i].size() == 0) return false;
            if(connected[i].size() == 1) leaf = i;
        }
        if(leaf == -1) return false;
        stk.push(leaf);

        while(!stk.empty()) {
            int node = stk.top();
            stk.pop();
            // loop
            if(seen.find(node) != seen.cend()) return false;
            seen.insert(node);
            for(auto adj : connected[node]) {
                if(seen.find(adj) == seen.cend()) {
                    stk.push(adj);
                }
            }
        }

        return seen.size() == n;
    }
};
