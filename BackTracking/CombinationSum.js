/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let ans = [];
    candidates.sort((a,b) =>  a - b);
    const helper = function(index, total, current) {
        if (total > target || index === candidates.length) return;
        if(total === target) 
            return ans.push(current.slice());
        else {
            current.push(candidates[index]);
            helper(index, total + candidates[index], current);
            current.pop(); 
            helper(index + 1, total, current);
        }
    }

    helper(0, 0, []);
    return ans;
};

console.log(combinationSum([1,2,3], 8));