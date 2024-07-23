#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int l = 0;
        int r = matrix.size() - 1;
        int n_length = matrix[0].size();
        int mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            // if (matrix[mid][0] == target) return true ;
            if (matrix[mid][0] <= target && matrix[mid][n_length - 1] >= target )
            {
                break;
            }
            if (matrix[mid][0] > target) r = mid - 1;
            else l = mid + 1;
        }

        l = 0;
        r = n_length - 1;
        int mid_two;

        while(l <= r)
        {
            mid_two = (l + r) / 2;
            if (matrix[mid][mid_two] == target) return true ;
            if (matrix[mid][mid_two] > target) r = mid_two - 1;
            else l = mid_two + 1;
        }

        return false;
    }
};


int main() {
Solution solution;
    vector<vector<int>> board = {{1}, {3}};

    cout << solution.searchMatrix(board, 3) << endl;

    return 0;
}