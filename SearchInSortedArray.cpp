#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // The numbers on the right are as they should be
            if (nums[mid] < nums[r])
            {
                // target is in range on right side
                if (target > nums[mid] && target <= nums[r] )
                {
                    l = mid + 1 ;
                }
                else
                {
                    r = mid - 1;
                }
            }
            // The numbers on the left are as they should be
            else
            {
                // target is in range on left side
                if (target >= nums[l] && target < nums[mid] )
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1 ;
                }
            }
        }
        return - 1;
    }
};


int main() {
Solution solution;
    vector<int> board = {1};
    cout << solution.search(board, 1) << endl;

    return 0;
}