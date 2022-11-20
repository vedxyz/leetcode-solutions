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
    int maxGain(TreeNode* node, int& maxsum) {
        if (!node) return 0;
        
        int left = max(maxGain(node->left, maxsum), 0);
        int right = max(maxGain(node->right, maxsum), 0);
        maxsum = max(maxsum, node->val + left + right);
        
        return node->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        maxGain(root, maxsum);
        return maxsum;
    }
};

