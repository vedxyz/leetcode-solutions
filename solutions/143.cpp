/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* node = head;
        
        while (node) {
            nodes.push_back(node);
            node = node->next;
        }
        
        node = head;
        for (int i = 1; i <= nodes.size() / 2; i++) {
            node->next = nodes[nodes.size() - i];
            node->next->next = nodes[i];
            node = node->next->next;
        }
        
        if (nodes.size() % 2 == 0)
            node->next = nodes[nodes.size() / 2];
        nodes[nodes.size() / 2]->next = NULL;
    }
};

