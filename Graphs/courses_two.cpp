#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> course_prereq{};
        vector<int> ans{};
        unordered_set<int> to_dfs{};

        for(auto& pair : prerequisites) {
            course_prereq[pair[0]].insert(pair[1]);
            // if(course_prereq.find(pair[1]) == course_prereq.cend()) {
            //     course_prereq[pair[1]] = {};
            // }
        }

        for(int i=0; i<numCourses; i++) {
            to_dfs.insert(i);
        }

        function<void(int)> dfs = [&](int course){
            // if(seen.find(x) != seen.cend())
            if(course_prereq[course].empty()) {
                ans.push_back(course);
                to_dfs.erase(course);
                return;
            }
            for(auto& prereq : course_prereq[course]) {
                dfs(prereq);
            }
            ans.push_back(course);
            to_dfs.erase(course);
            return;
        };

        while(!to_dfs.empty()) {
            dfs(*to_dfs.begin());
            if(loop_found) break;
        };

        return ans;
    }
};