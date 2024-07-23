

function solveNQueens(n: number): string[][] {
    let ans : string[][] = [];
    let current : string[] = new Array(n).fill(".".repeat(n));

    const works = function(i: number, j: number) {
        for(let it = 0; it < i; it++)
        {
            if(current[it][j] == "Q") return false;
            // if(current[i][it] == "Q") return false;
        }
        // check top left
        let k = i - 1 
        let l = j - 1;
        while (k > 0 && l > 0) {
            if (current[k][l] == "Q") return false;
            k--;
            l--;
        }

        // check top right
        k = i - 1 
        l = j + 1;
        while (k > 0 && l < current.length) {
            if (current[k][l] == "Q") return false;
            k--;
            l++;
        }
        return true;
    };

    const helper = function(queens: number, row : number) {
        if (queens == n) return ans.push(current.slice());
        let oneWorked = false;
        for(let j = 0; j < current.length; j++) {
            if(works(row,j)) {
                oneWorked = true;
                let prev = current[row];
                current[row] = current[row].substring(0, j) + "Q" + current[row].substring(j + 1);;
                helper(queens + 1, row + 1);
                current[row] = prev;
            }
        }
        if (!oneWorked) return;
    }

    helper(0, 0);
    return ans;
};

console.log(solveNQueens(4));