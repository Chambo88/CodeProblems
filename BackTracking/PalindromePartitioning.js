function partition(s) {
    var ans = [];
    var isPalindrome = function (check) {
        if (check === '')
            return false;
        var l = 0;
        var r = check.length - 1;
        while (l < r) {
            if (check[l] != check[r])
                return false;
            l++;
            r--;
        }
        return true;
    };
    var helper = function (index, party, currentBuild) {
        if (index == s.length) {
            if (currentBuild.length == 0)
                ans.push(party.slice());
            return;
        }
        ;
        if (isPalindrome(currentBuild + s[index])) {
            party.push(currentBuild + s[index]);
            helper(index + 1, party, '');
            party.pop();
        }
        helper(index + 1, party, currentBuild + s[index]);
    };
    helper(0, [], '');
    return ans;
}
;
console.log(partition("aaba"));
