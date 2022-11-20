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
    void recursion(vector<vector<int>>& levels, TreeNode* node, int level = 0) {
        if (!node) return;
        if (levels.size() == level)
            levels.push_back({});
        
        levels[level].push_back(node->val);
        recursion(levels, node->left, level + 1);
        recursion(levels, node->right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        recursion(levels, root);
        return levels;
    }
};

class IterativeSolution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> levels;
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        
        while (!bfs.empty()) {
            TreeNode* node = bfs.front().first;
            int level = bfs.front().second;
            bfs.pop();
            
            if (levels.size() == level)
                levels.push_back({});
            levels[level].push_back(node->val);
            
            if (node->left)
                bfs.push({node->left, level + 1});
            if (node->right)
                bfs.push({node->right, level + 1});
        }
        
        return levels;
    }
};
