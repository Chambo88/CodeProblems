#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start <= end)
        {
            if(!isalpha(s[start]) || !isdigit(s[start])) start++;
            else if (!isalpha(s[end]) || !isdigit(s[end])) end--;
            else 
            {
                if(tolower(s[start]) != tolower(s[end]))
                {
                    return false;
                }
                start++;
                end--;
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