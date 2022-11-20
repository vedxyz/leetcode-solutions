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
    int postorderIdx;
    unordered_map<int, int> inorderIdxMap;
    
    TreeNode* arrayToTree(vector<int>& postorder, int left, int right) {
        if (left > right) return NULL;
        
        int rootVal = postorder[postorderIdx--];
        TreeNode* root = new TreeNode(rootVal);
        root->right = arrayToTree(postorder, inorderIdxMap[rootVal] + 1, right);
        root->left = arrayToTree(postorder, left, inorderIdxMap[rootVal] - 1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIdx = postorder.size() - 1;
        for (int i = 0; i != inorder.size(); i++)
            inorderIdxMap[inorder[i]] = i;
        return arrayToTree(postorder, 0, postorder.size() - 1);
    }
};