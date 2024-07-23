function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
    if(!root) return true;
    let isGoodTree = true;
    function DFS(root) {
        if(!root) return [null, null];
        let min_max_tuple_left = DFS(root.left);
        if (min_max_tuple_left[1] !== null && min_max_tuple_left[1] >= root.val)
        {
            isGoodTree = false
        }
        let min_max_tuple_right = DFS(root.right);
        if (min_max_tuple_right[0] !== null && min_max_tuple_right[0] <= root.val)
        {
            isGoodTree = false
        }
        let min = Math.min(min_max_tuple_left[0]?? Infinity, min_max_tuple_right[0]?? Infinity, root.val );
        let max = Math.max(min_max_tuple_left[1]?? -Infinity, min_max_tuple_right[1]?? -Infinity, root.val );
        return [min, max]
    }

    DFS(root);
    return isGoodTree;
};

// Test cases
function runTests() {
    // Test Case 1: Empty tree
    // let root1 = null;
    // console.log(isValidBST(root1)); // Expected output: []

    // // Test Case 2: Tree with one node
    // let root2 = new TreeNode(1);
    // console.log(isValidBST(root2)); // Expected output: [[1]]

    // Test Case 3: Tree with multiple levels
    let root3 = new TreeNode(5);
    root3.left = new TreeNode(1);
    root3.right = new TreeNode(4);
    root3.right.left = new TreeNode(3);
    root3.right.right = new TreeNode(6);
    console.log(isValidBST(root3)); // Expected output: [[1], [2, 3], [4, 5, 6, 7]]

}

// Run the tests
runTests();