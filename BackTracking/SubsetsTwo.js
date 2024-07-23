/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    let ans = new Set([]);

    const computer = function (current, index) {
        if (index == nums.length) return;
        for (let i = index; i < nums.length; i++ ) {
            current.push(nums[index]);
            ans.add(current);
            computer(current, index + 1);
            current.pop();
            computer(current, index + 1);
        }
    }

    return ans;
};