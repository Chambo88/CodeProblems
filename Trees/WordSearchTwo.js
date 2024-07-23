var Node = function(val, x, y) {
    this.val = val;
    this.connected = [];
    this.position = [x, y];
}


/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(board, words) {
    let obj_board = Array.from({ length: board.length }, () => Array(board[0].length).fill(null));
    // create board
    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[i].length; j++) {
            obj_board[i][j] = new Node(board[i][j], i, j);
        }
    }
    // connect board
    for(let i = 0; i < obj_board.length; i++) {
        for(let j = 0; j < obj_board[i].length; j++) {
            // connect top
            if (i != 0) {
                obj_board[i][j].connected.push(obj_board[i - 1][j]);
            }
            // connect left
            if (j != 0) {
                obj_board[i][j].connected.push( obj_board[i][j - 1]);
            }
            // connect right
            if (j < obj_board[i].length - 1) {
                obj_board[i][j].connected.push(obj_board[i][j + 1]);
            }
            // connect bottom
            if (i < obj_board.length - 1) {
                obj_board[i][j].connected.push(obj_board[i + 1][j]);
            }
        }
    }

    // what words do we see
    const helper = (node, word, visited, index) => {
        if (word.length == index + 1) return word[index] == node.val;
        if (node.val == word[index]) {
            visited.add(node.position.toString());
            for(let connected_node of node.connected) {
                if(!visited.has(connected_node.position.toString())) {
                    var contains_word = helper(connected_node, word, visited, index + 1)
                    if (contains_word) return true;
                }
            }
            visited.delete(node.position.toString());
        }
        return false;
    }

    let ans = [];

    for(let word of words) {
        // find start nodes
        let start = [];
        for(let row of obj_board) {
            for(let node of row) {
                if (node.val == word[0]) {
                    start.push(node);
                }
            }
        }
        // eval node
        for(let start_node of start) {
            if (helper(start_node, word, new Set(), 0)) {
                ans.push(word);
                break;
            }
        }
    }

    return ans;
};