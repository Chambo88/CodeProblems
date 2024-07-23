/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    ans = []

    const computer = (numbers_left, built_array) => {
        if(numbers_left.size === 0) return ans.push(built_array.slice());
        for (let num of numbers_left) {
            built_array.push(num);
            numbers_left.delete(num);
            computer(numbers_left, built_array);
            numbers_left.add(num);
            built_array.pop();
        }
    }
    computer(set, []);
    return ans;
};

console.log(permute([1,2,3]));