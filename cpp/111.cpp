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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root)
            q.push(pair(root, 1));
        
        while (!q.empty()) {
            pair<TreeNode*, int> node = q.front();
            q.pop();
            
            if (!node.first->left && !node.first->right)
                return node.second;
            
            if (node.first->left)
                q.push(pair(node.first->left, node.second + 1));
            
            if (node.first->right)
                q.push(pair(node.first->right, node.second + 1));
        }
        
        return 0;
    }
};

