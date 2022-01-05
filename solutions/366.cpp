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
class DestructiveSolution { // Destroys tree to terminate traversal
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        stack<TreeNode*> dfs;
        
        while (!isLeaf(root) || !dfs.empty()) {
            if (dfs.empty())
                dfs.push(root);
            
            TreeNode* node = dfs.top();
            dfs.pop();
            
            if (node == root)
                leaves.push_back({});
            
            if (node->right) {
                if (isLeaf(node->right)) {
                    leaves[leaves.size() - 1].push_back(node->right->val);
                    node->right = NULL;
                } else dfs.push(node->right);
            }
            
            if (node->left) {
                if (isLeaf(node->left)) {
                    leaves[leaves.size() - 1].push_back(node->left->val);
                    node->left = NULL;
                } else dfs.push(node->left);
            }
        }
        leaves.push_back({root->val});
        
        return leaves;
    }
};

class PreservingSolution { // Uses memory space to keep tree intact while traversing
    unordered_set<TreeNode*> used;
    
    bool isLeaf(TreeNode* node) {
        return !isVisitable(node->left) && !isVisitable(node->right);
    }
    bool isVisitable(TreeNode* node) {
        return node && !used.count(node);
    }
    void visitNode(TreeNode* node, vector<vector<int>>& leaves) {
        leaves[leaves.size() - 1].push_back(node->val);
        used.insert(node);
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        stack<TreeNode*> dfs;
        
        while ((!isLeaf(root)) || !dfs.empty()) {
            if (dfs.empty())
                dfs.push(root);
            
            TreeNode* node = dfs.top();
            dfs.pop();
            
            if (node == root)
                leaves.push_back({});
            
            if (isVisitable(node->right)) {
                if (isLeaf(node->right))
                    visitNode(node->right, leaves);
                else dfs.push(node->right);
            }
            
            if (isVisitable(node->left)) {
                if (isLeaf(node->left))
                    visitNode(node->left, leaves);
                else dfs.push(node->left);
            }
        }
        leaves.push_back({root->val});
        
        return leaves;
    }
};

