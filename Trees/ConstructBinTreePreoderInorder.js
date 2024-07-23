// [5,3,2,1]

function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}


/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    const dfs = (arr) => {
        if (arr.length == 0)
        {
            return null;
        }
        // if (arr.length == 1)
        // {
        //     return TreeNode(arr[0]);
        // }
        
        // if (arr.includes(preorder[0]))
        // {
            let indexOf = arr.indexOf(preorder[0]);
            let leftSide = arr.slice(0, indexOf);
            let rightSide = arr.slice(indexOf + 1);

            // cut the arr by the value
            return new TreeNode(preorder.shift(), dfs(leftSide), dfs(rightSide))
        // }
        // else
        // {
        //     return null;
        // }
    }

    return dfs(inorder);


};

// Test cases
function runTests() {

    // Test Case 2: Tree with one node
    let root2 = new TreeNode(1, 1);
    console.log(kthSmallest(root2, 1)); // Expected output: [[1]]

    // Test Case 3: Tree with multiple levels
    // let root3 = new TreeNode(3);
    // root3.left = new TreeNode(1);
    // root3.right = new TreeNode(4);
    // root3.left.right = new TreeNode(2);
    // console.log(kthSmallest(root3, 1)); // Expected output: [[1], [2, 3], [4, 5, 6, 7]]

}

// Run the tests
runTests();