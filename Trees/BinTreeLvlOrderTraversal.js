/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) return [];
    let queue = [root];
    let ans = []

    while(queue.length > 0)
    {
        let nodes_at_level = [];
        let current_queue_length = queue.length;
        for(var i=0; i<current_queue_length; i++)
        {
            let node = queue.shift();
            nodes_at_level.push(node.val);
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
        ans.push(nodes_at_level);
    }
    return ans;
};

// Test cases
function runTests() {
    // Test Case 1: Empty tree
    let root1 = null;
    console.log(levelOrder(root1)); // Expected output: []

    // Test Case 2: Tree with one node
    let root2 = new TreeNode(1);
    console.log(levelOrder(root2)); // Expected output: [[1]]

    // Test Case 3: Tree with multiple levels
    let root3 = new TreeNode(1);
    root3.left = new TreeNode(2);
    root3.right = new TreeNode(3);
    root3.left.left = new TreeNode(4);
    root3.left.right = new TreeNode(5);
    root3.right.left = new TreeNode(6);
    root3.right.right = new TreeNode(7);
    console.log(levelOrder(root3)); // Expected output: [[1], [2, 3], [4, 5, 6, 7]]

    // Test Case 4: Left-skewed tree
    let root4 = new TreeNode(1);
    root4.left = new TreeNode(2);
    root4.left.left = new TreeNode(3);
    root4.left.left.left = new TreeNode(4);
    console.log(levelOrder(root4)); // Expected output: [[1], [2], [3], [4]]

    // Test Case 5: Right-skewed tree
    let root5 = new TreeNode(1);
    root5.right = new TreeNode(2);
    root5.right.right = new TreeNode(3);
    root5.right.right.right = new TreeNode(4);
    console.log(levelOrder(root5)); // Expected output: [[1], [2], [3], [4]]
}

// Run the tests
runTests();
