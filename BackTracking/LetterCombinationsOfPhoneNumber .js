function letterCombinations(digits) {
    var ans = [];
    var current = "";
    if (digits.length == 0)
        return ans;
    var map = {
        "2": ["a", "b", "c"],
        "3": ['d', 'e', 'f'],
        "4": ['g', 'h', 'i'],
        "5": ['j', 'k', 'l'],
        "6": ['m', 'n', 'o'],
        "7": ['p', 'q', 'r', 's'],
        "8": ['t', 'u', 'v'],
        "9": ['w', 'x', 'y', 'z']
    };
    var backtracker = function (index) {
        if (index == digits.length)
            return ans.push(current.slice());
        for (var _i = 0, _a = map[digits[index]]; _i < _a.length; _i++) {
            var letter = _a[_i];
            current += letter;
            backtracker(index + 1);
            current.slice(0, -1);
        }
    };
    return ans;
}
;
console.log(letterCombinations("23"));
