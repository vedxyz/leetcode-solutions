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

    // Recursive DFS
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        
        if (!root) return 0;
        if (low <= root->val && root->val <= high)
            result += root->val;
        if (root->val >= low)
            result += rangeSumBST(root->left, low, high);
        if (root->val <= high)
            result += rangeSumBST(root->right, low, high);
        
        return result;
    }
    
    // Iterative DFS
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            
            if (top->left && top->val >= low)
                s.push(top->left);
            if (top->right && top->val <= high)
                s.push(top->right);
            
            if (low <= top->val && top->val <= high)
                result += top->val;
        }
        
        return result;
    }
    
    // Iterative BFS
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            if (q.front()->left && q.front()->val >= low)
                q.push(q.front()->left);
            if (q.front()->right && q.front()->val <= high)
                q.push(q.front()->right);
            
            if (low <= q.front()->val && q.front()->val <= high)
                result += q.front()->val;
            
            q.pop();
        }
        
        return result;
    }
};
