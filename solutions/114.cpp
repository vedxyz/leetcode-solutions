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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode dummy;
        TreeNode* curNode = &dummy;
        
        stack<TreeNode*> dfs;
        dfs.push(root);
        while (!dfs.empty()) {
            TreeNode* node = dfs.top();
            dfs.pop();
            
            curNode = curNode->right = node;
            
            if (node->right)
                dfs.push(node->right);
            if (node->left)
                dfs.push(node->left);
            
            node->left = node->right = NULL;
        }
    }
};

