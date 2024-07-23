#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // course, prereqs
        unordered_map<int, unordered_set<int>> map{};
        queue<int> q{};
        int count = 0;

        for(const auto& prereq : prerequisites) {
            map[prereq[0]].insert(prereq[1]);
            if(map.find(prereq[1]) == map.cend()) {
                map[prereq[1]] = {};
            }
        }

        // get starting points
        for(const auto& [course, prereqs]: map) {
            if(prereqs.size() == 0) q.push(course);
        }

        // bfs over starting points
        while(!q.empty()) {
            int q_length = q.size();
            for(int i=0; i<q_length; i++) {
                int course = q.front();
                q.pop();
            }

        }
    }

};