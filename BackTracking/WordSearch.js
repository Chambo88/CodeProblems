function exist(board, word) {
    var exists = false;
    var row_size = board.length;
    var col_size = board[0].length;
    var backtrackFunction = function (i, j, index) {
        if (word.length - 1 == index)
            exists = true;
        var prev_letter = board[i][j];
        board[i][j] = "#";
        index++;
        if (i > 0 && board[i - 1][j] == word[index]) {
            backtrackFunction(i - 1, j, index);
        }
        let temp = board[i][j-1];
        let temp2 = word[index];
        if (i + 1 < row_size && board[i + 1][j] == word[index]) {
            backtrackFunction(i + 1, j, index);
        }
        if (j > 0 && board[i][j - 1] == word[index]) {
            backtrackFunction(i, j - 1, index);
        }
        if (j + 1 < col_size && board[i][j + 1] == word[index]) {
            backtrackFunction(i, j + 1, index);
        }
        board[i][j] = prev_letter;
    };
    for (var i = 0; i < board.length; i++) {
        for (var j = 0; j < board[i].length; j++) {
            if (board[i][j] === word[0]) {
                backtrackFunction(i, j, 0);
                if (exists)
                    return true;
            }
        }
    }
    return false;
}
;
console.log(exist([["C", "A", "A"], ["A", "A", "A"], ["B", "C", "D"]], "AAB"));
