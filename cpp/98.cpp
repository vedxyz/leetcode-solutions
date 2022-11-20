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
public:
    bool isValidBST(TreeNode* root, TreeNode* lower = NULL, TreeNode* upper = NULL) {
        if (!root) return true;
        if ((lower && root->val <= lower->val) || (upper && root->val >= upper->val)) return false;
        
        return isValidBST(root->left, lower, root) && isValidBST(root->right, root, upper);
    }
};
