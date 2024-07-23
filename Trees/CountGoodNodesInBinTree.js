function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @return {number[]}
 */

/**
 * @param {TreeNode} root
 * @return {number}
 */
var goodNodes = function(root) {
    return goodNodesTwo(root, 0);
};

var goodNodesTwo = function(root, max) {
    if (!root) return 0;
    if(root.val >= max) return 1 + goodNodes(root.left, root.val) + goodNodes(root.right, root.val);
    return goodNodes(root.left, max) + goodNodes(root.right, max);
}

// Test cases
function runTests() {
    // Test Case 1: Empty tree
    let root1 = null;
    console.log(goodNodes(root1)); // Expected output: []

    // Test Case 2: Tree with one node
    let root2 = new TreeNode(1);
    console.log(goodNodes(root2)); // Expected output: [[1]]

    // Test Case 3: Tree with multiple levels
    let root3 = new TreeNode(3);
    root3.left = new TreeNode(1);
    root3.right = new TreeNode(4);
    root3.left.left = new TreeNode(3);
    root3.right.left = new TreeNode(1);
    root3.right.right = new TreeNode(5);
    console.log(goodNodes(root3)); // Expected output: [[1], [2, 3], [4, 5, 6, 7]]

}

// Run the tests
runTests();