#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int count = 30;
        int slow = 0;
        int fast = 0;
        while (true)
        {
            cout << nums [slow] << " - pt1 : pt2 - " << nums[fast] << endl;
            cout << slow << " - slow : fast - " << fast << endl;
            if (nums[fast] == nums[slow] && slow != fast) return nums[slow];
            fast = ( fast + 2 ) % nums.size();
            slow = ( slow + 1 ) % nums.size();
            if (count == 0) break;
            count--;
        }
        return nums[slow];
    }
};

int main() {
Solution solution;
    vector<int> board = {3,1,3,4,2
    };

    auto result = solution.findDuplicate(board);

    cout << result << endl;

    return 0;
}