#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        priority_queue<int> pq(nums.begin(), nums.end());

        for(int i = 0; i < k - 1; i++) {
           pop_heap(nums.begin(), nums.end());
        }
        return nums[0];

    }
};