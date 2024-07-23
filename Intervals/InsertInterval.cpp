#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int it = 0;
        vector<vector<int>> ans{};
        while(intervals[it][1] < newInterval[0] && it < intervals.size()) {
            ans.push_back(intervals[it]);
            it++;
        }
        int start_of_new = min(newInterval[0], intervals[it][0]);
        while(intervals[it][0] <= newInterval[1] && it < intervals.size()) {
            it++;
        }
        int end_of_new = max(newInterval[1], intervals[it-1][1]);
        ans.push_back({start_of_new, end_of_new});
        while(it < intervals.size()) {
            ans.push_back(intervals[it]);
            it++;
        }
        return ans;
    }
};

