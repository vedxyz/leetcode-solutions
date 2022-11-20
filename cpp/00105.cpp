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
    int preorderIdx;
    unordered_map<int, int> inorderIdxMap;
    
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if (left > right) return NULL;
        
        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = arrayToTree(preorder, left, inorderIdxMap[rootVal] - 1);
        root->right = arrayToTree(preorder, inorderIdxMap[rootVal] + 1, right);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIdx = 0;
        for (int i = 0; i != inorder.size(); i++)
            inorderIdxMap[inorder[i]] = i;
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
};
