#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 


using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[(mid - 1 + nums.size()) % nums.size()] > nums[mid])
            {
                return nums[mid];
            }
            if(nums[mid] < nums[r])
            {
                r = mid - 1;
            } else
            {
                l = mid + 1;
            }
        }
        return nums[mid];
    }
};


int main() {
Solution solution;
    vector<int> board = {11,13,15,17};
    cout << solution.findMin(board) << endl;

    return 0;
}