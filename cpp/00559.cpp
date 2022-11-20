/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0;
        queue<pair<Node*, int>> q;
        if (root) q.push(pair(root, 1));
        
        while (!q.empty()) {
            pair<Node*, int> node = q.front();
            q.pop();
            
            depth = max(depth, node.second);
            
            for (int i = 0; i != node.first->children.size(); i++)
                q.push(pair(node.first->children[i], node.second + 1));
        }
        
        return depth;
    }
};

