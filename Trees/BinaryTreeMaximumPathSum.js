// [5,3,2,1]

function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}


/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function(root) {
    let maxSum = Number.NEGATIVE_INFINITY;

    dfs = (root) => {
        if (!root) return 0;

        let leftMax = dfs(root.left);
        let rightMax = dfs(root.right);

        maxSum = Math.max(leftMax  + root.val, rightMax  + root.val, leftMax + rightMax + root.val, root.val, maxSum);
        return Math.max(leftMax + root.val, rightMax + root.val, root.val);
    }

    dfs(root);
    return maxSum; 
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