#include <vector>
#include <unordered_map>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<bool> seen(edges.size() + 1, false);
        vector<vector<int>> adj_list(edges.size() + 1, vector<int>{});
        vector<int> ans{};

        for(const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        bool found_cycle = false;
        const function<void(int)> dfs = [&](int node) {
            if(adj_list[node].empty() || found_cycle) return;
            seen[node] =  true;
            for(auto bud : adj_list[node]) {
                if (seen[bud]) {
                    seen.push_back(bud);
                    found_cycle = true;
                    return;
                }

                dfs(bud);
            }
            seen.pop_back();
        };

        vector<vector<int>> potential_answers{};

        int doubled_val = seen.back();
        int prev = doubled_val;
        seen.pop_back();
        while(doubled_val != seen.back()) {
            int a = seen.back();
            potential_answers.push_back(
                (a > prev) ? vector<int>{prev, a} : vector<int>{prev, a}
            );
            seen.pop_back();
        }
        int a = seen.back();
        potential_answers.push_back(
            (a > prev) ? vector<int>{prev, a} : vector<int>{prev, a}
        );

        for(int i = edges.size() - 1; i >= 0 ;i--) {
            for(auto ans_pair : potential_answers) {
                if (edges[i][0] == ans_pair[0] && edges[i][1] == ans_pair[1])
                    return ans_pair;
            }
        }
        return {};
    }
};