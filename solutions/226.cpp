/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void invert(TreeNode* node) {
        if (!node) return;
        
        invert(node->left);
        invert(node->right);
        
        swap(node->left, node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
