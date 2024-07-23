/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    candidates.sort((a,b) => a - b);
    let ans = [];

    /**
     * @param {number} total
     * @param {number} index
     * @param {number[]} build_array
     * @return {void}
     */
    const helper = (total, index, build_array) => {
        if (total === target) {
            ans.push(build_array.slice());
            return;
        };
        if (total > target || index === candidates.length) return;

        build_array.push(candidates[index]);
        helper(total + candidates[index], index + 1, build_array);
        build_array.pop();

        let val = candidates[index]
        while(index < candidates.length || candidates[index] == val) {
            index++;
        }
        helper(total, index, build_array);
    }

    helper(0, 0, []);
    return ans;
};

console.log(combinationSum2([2,3, 4, 5, 1, 1, 3, 2, 3], 5));