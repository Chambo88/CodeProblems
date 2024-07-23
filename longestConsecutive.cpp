#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_nums(nums.begin(), nums.end());

        int max = 0;

        for(auto& num : set_nums) 
        {
            if (set_nums.find(num - 1) == set_nums.cend())
            {
                int count = 1;
                int next = 1;
                while(set_nums.find(num + next++) != set_nums.cend())
                {
                    count++;
                }
                if (count > max) max = count;
            }
        }

        return max;
    }
};


int main() {
Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '1'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solution.isValidSudoku(board)) {
        cout << "The board is a valid Sudoku." << endl;
    } else {
        cout << "The board is not a valid Sudoku." << endl;
    }

    return 0;
}