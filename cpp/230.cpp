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
    // Heap Solution
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> bfs;
        priority_queue<int> heap;
        bfs.push(root);
        
        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();
            
            heap.push(node->val);
            if (heap.size() > k)
                heap.pop();
            
            if (node->left)
                bfs.push(node->left);
            if (node->right)
                bfs.push(node->right);
        }
        
        return heap.top();
    }
    
    // BST Inorder Traversal Solution
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> dfs;
        dfs.push(root);
        
        while (true) {
            while (root) {
                dfs.push(root);
                root = root->left;
            }
            root = dfs.top();
            dfs.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
        
        return 0;
    }
};

