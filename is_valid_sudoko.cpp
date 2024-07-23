#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row_check(9, vector<bool>(9, false));
        vector<vector<bool>> col_check(9, vector<bool>(9, false));
        vector<vector<bool>> box_check(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1'; // '1' -> 0, '2' -> 1, ..., '9' -> 8
                    int box_index = (i / 3) * 3 + (j / 3);

                    // Check for duplicates in the row, column, and box
                    if (row_check[i][num] || col_check[j][num] || box_check[box_index][num]) {
                        return false;
                    }

                    // Mark the number as seen
                    row_check[i][num] = true;
                    col_check[j][num] = true;
                    box_check[box_index][num] = true;
                }
            }
        }

        return true;
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