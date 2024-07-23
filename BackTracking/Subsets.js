/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let output = [[]];

    for(let num of nums) {
        let length = output.length;
        for(let i=0; i < length; i++) {
            let newSubset = output[i].slice();
            newSubset.push(num)
            output.push(newSubset);
        }
    }
    return output;
};