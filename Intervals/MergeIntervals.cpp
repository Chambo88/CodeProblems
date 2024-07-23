#include <vector>
#include <algorithm>

using namespace std;

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        vector<vector<int>> ans{intervals[0]};

        sort(intervals.begin(), intervals.end(), [](vector<int> left, vector<int> right) {
            left[0] < right[0];
        });

        for(int i=1; i<intervals.size(); i++) {
            // intersect
            if(ans[ans.size() - 1][1] >= intervals[i][0]) {
                ans[ans.size() -1][1] = max(intervals[i][1], ans[ans.size() -1][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};