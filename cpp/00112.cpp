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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> dfs;
        dfs.push({root, root->val});
        
        while (!dfs.empty()) {
            TreeNode* node = dfs.top().first;
            int sum = dfs.top().second;
            dfs.pop();
            
            if (!node->left && !node->right && sum == targetSum)
                return true;
            
            if (node->right)
                dfs.push({node->right, sum + node->right->val});
            if (node->left)
                dfs.push({node->left, sum + node->left->val});
        }
        
        return false;
    }
};

