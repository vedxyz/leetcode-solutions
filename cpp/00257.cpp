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
    void traverse(TreeNode* node, vector<string>& paths, string path) {
        if (!node) return;
        
        path += to_string(node->val);
        
        if (!node->left && !node->right)
            paths.push_back(path);
        
        path += "->";
        traverse(node->left, paths, path);
        traverse(node->right, paths, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        traverse(root, paths, "");
        return paths;
    }
};

