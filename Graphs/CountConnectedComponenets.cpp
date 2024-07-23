#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n, vector<int>{});
        unordered_set<int> to_dfs{};

        int components = 0;

        for(int i=0; i<n; i++) {
            to_dfs.insert(i);
        }

        for(const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        while(!to_dfs.empty()) {
            components += 1;
            unordered_set<int> visited{};
            stack<int> current_compenent{};
            int start_node = *to_dfs.begin();
            visited.insert(start_node);
            current_compenent.push(start_node);
            to_dfs.erase(start_node);
            while(!current_compenent.empty()) {
                int current = current_compenent.top();
                current_compenent.pop();

                for(auto connected : adj_list[current]) {
                    if(!(visited.find(connected) != visited.cend())) {
                        visited.insert(connected);
                        current_compenent.push(connected);
                        to_dfs.erase(connected);
                    }
                }
            }
        }

        return components;
    }
};