#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int searchIndex;
        int bottom = 0;
        int top = nums.size() - 1;

        while(bottom <= top)
        {
            searchIndex = (top + bottom) / 2;
            if (target == nums[searchIndex])
            {
                return searchIndex;
            }
            else if(target > nums[searchIndex]) bottom = searchIndex + 1;
            else top = searchIndex - 1;

        }
        return -1;
    }
};


int main() {
Solution solution;
    vector<int> board = {-1,0,3,5,9,12
    };

    cout << solution.search(board, 8) << endl;

    return 0;
}