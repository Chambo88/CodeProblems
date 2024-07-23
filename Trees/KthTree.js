// [5,3,2,1]

function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let element = -1;
    let count = 0;

    function dfs(node) {
        if (!node) return 0;
        
        let left_count = dfs(node.left);

        if (++count == k) {
            element = node.val;
            return 0;
        }

        let right_count = dfs(node.right);

        return left_count + right_count + 1;
    }

    dfs(root);
    return element;
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