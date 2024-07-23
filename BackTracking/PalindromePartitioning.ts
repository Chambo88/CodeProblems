function partition(s: string): string[][] {
    let ans : string[][] = [];
    let party : string[] = [];

    const isPalindrome = function(check: string): boolean {
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
    }

    const helper = function (index: number, currentBuild: string) : void {
        if (index == s.length) {
            if (currentBuild.length == 0)
                ans.push(party.slice());
            return;
        }
        ;
        if (isPalindrome(currentBuild + s[index])) {
            party.push(currentBuild + s[index]);
            helper(index + 1, '');
            party.pop();
        }
        helper(index + 1, currentBuild + s[index]);
    }

    helper(0, '');
    return ans;
};

console.log(partition("aa"));