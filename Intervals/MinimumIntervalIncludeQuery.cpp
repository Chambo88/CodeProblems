#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        if(intervals.size() == 0) return vector<int>(queries.size()-1, -1);
        vector<int> ans{};

        // Sort original list by start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ends = intervals;
        // Sort end times
        sort(ends.begin(), ends.end(), [](vector<int> one, vector<int> two) {
            return one[1] < two[1];
        });

        for(int i=0; i<queries.size(); i++) {
            ans.push_back(calculateMin(intervals, ends, queries[i]));
        }

        return ans;
    }

    int calculateMin(vector<vector<int>>& intervals, vector<vector<int>>& ends, int find) {
        int i = 0;
        int j = 0;
        multiset<int> current_times = {};

        while(j < ends.size()) {
            // at a start point
            if (i < intervals.size() && intervals[i][0] <= ends[j][1]) {
                if(intervals[i][0] > find) {
                    break;
                }

                current_times.insert(intervals[i][1] - intervals[i][0] + 1);
                i++;
            } else { // at an end point
                if(ends[j][1] >= find) {
                    break;
                }
                auto it = current_times.find(ends[j][1] - ends[j][0] + 1);
                current_times.erase(it);

                j++;
            }

            cout << endl;
        }

        if(current_times.size() == 0) return -1;
        return *current_times.begin();
    }
    
};

int main() {
    Solution solution;

    // Define test intervals and queries
    vector<vector<int>> intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
    vector<int> queries = {2, 3, 4, 5};

    // 4, 3, 4 //

    // Get the results
    vector<int> results = solution.minInterval(intervals, queries);

    // Print the results
    cout << "Results for the given queries: ";
    for (const auto& result : results) {
        cout << result << " ";
    }
    cout << endl;

    // Additional test cases
    vector<vector<int>> intervals2 = {{1, 3}, {2, 5}, {3, 9}};
    vector<int> queries2 = {1, 4, 7};

    // Get the results for the additional test cases
    results = solution.minInterval(intervals2, queries2);

    // Print the results
    cout << "Results for the additional queries: ";
    for (const auto& result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}