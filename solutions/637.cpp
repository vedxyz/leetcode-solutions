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
    vector<double> averageOfLevels(TreeNode* root) {
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
        
        vector<double> avgs(levels.size());
        for (int i = 0; i != levels.size(); i++) {
            double sum = 0;
            for (int j = 0; j != levels[i].size(); j++)
                sum += levels[i][j];
            avgs[i] = sum / levels[i].size();
        }
        
        return avgs;
    }
};

