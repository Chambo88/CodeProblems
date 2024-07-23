type DigitMap = {
    [key: string]: string[];
};

function letterCombinations(digits: string): string[] {
    let ans : string[] = [];
    let current : string = "";
    if (digits.length == 0) return ans;
    let map : DigitMap = {
        "2" : ["a", "b", "c"],
        "3" : ['d', 'e', 'f'],
        "4" : ['g','h','i'],
        "5" : ['j','k','l'],
        "6" : ['m','n','o'],
        "7" : ['p','q','r','s'],
        "8" : ['t','u','v'],
        "9" : ['w','x','y','z']
    }

    const backtracker = function(index : number) {
        if (index == digits.length) return ans.push(current.slice());
        for (let letter of map[digits[index]]) {
            current += letter;
            backtracker(index + 1)
            current = current.slice(0,-1);
        }
    }
    backtracker(0);

    return ans;
};

console.log(letterCombinations("23"));