#include <iostream>
#include <vector>
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
    int diameterOfBinaryTree(TreeNode* root) {
        siftTree(root);
        return result;
    }

    int siftTree(TreeNode* root)
    {
        if(!root) return 0;
        int left_max = siftTree(root->left);
        int right_max = siftTree(root->right);
        result = max(result,  left_max + right_max);
        return 1 + max(left_max, right_max);
    }

private:
    int result = 0;
};
