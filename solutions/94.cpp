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
    // Recursive Solution
    void traverse(TreeNode* node, vector<int>& result) {
        if (!node) return;
        traverse(node->left, result);
        result.push_back(node->val);
        traverse(node->right, result);
    }
public:
    // Iterative Solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        stack<TreeNode*> stk;
        TreeNode* node = root;
        
        while (node || !stk.empty()) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
            
            node = stk.top(); stk.pop();
            result.push_back(node->val);
            node = node->right;
        }
        
        return result;
    }
};

