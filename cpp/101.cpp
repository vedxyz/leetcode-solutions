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
class RecursiveSolution {
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val
            && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};

class IterativeSolution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root->left == root->right) return true;
        if (!(root->left) || !(root->right)) return false;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        
        while (!q.empty()) {
            
            TreeNode* left = q.front().first;
            TreeNode* right = q.front().second;
            q.pop();
            
            if ((!left && right) || (left && !right)) return false;
            if (left->val != right->val)
                return false;
            
            if (left->left || right->right)
                q.push({left->left, right->right});
            if (left->right || right->left)
                q.push({left->right, right->left});
        }
        
        return true;
    }
};
