#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        findDepths(root);
        return m_is_balanced;
    }

    int findDepths(TreeNode* root) 
    {
        if (root == nullptr)
        {

        }
        else
        {
            int left_depth = findDepths(root->left);
            int right_depth = findDepths(root->right);
            if (abs(left_depth - right_depth) > 1) m_is_balanced = false;
            return 1 + max(left_depth, right_depth);
        }
    }


private:
    bool m_is_balanced = true;
};


TreeNode* buildTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(8);
    return root;
}

int main() {
    TreeNode* root = buildTree();
    Solution solution;
    bool result = solution.isBalanced(root);
    cout << "Is the tree balanced? " << (result ? "Yes" : "No") << endl;

    // Clean up the allocated memory
    delete root->left->left->left;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
