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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> paths;
        stack<tuple<TreeNode*, int, vector<int>>> dfs;
        dfs.push({root, root->val, {root->val}});
        
        while (!dfs.empty()) {
            TreeNode* node;
            int sum;
            vector<int> path;
            tie(node, sum, path) = dfs.top();
            dfs.pop();
            
            if (!node->left && !node->right && sum == targetSum)
                paths.push_back(path);
            
            if (node->right) {
                vector<int> pathr = path;
                pathr.push_back(node->right->val);
                dfs.push({node->right, sum + node->right->val, pathr});
            }
            if (node->left) {
                vector<int> pathl = path;
                pathl.push_back(node->left->val);
                dfs.push({node->left, sum + node->left->val, pathl});
            }
        }
        
        return paths;
    }
};

