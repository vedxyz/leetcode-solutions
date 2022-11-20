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
    ListNode* middleNode(ListNode* head) {
        ListNode* nodeL = head;
        ListNode* nodeR = head;
        
        while (nodeR != NULL && nodeR->next != NULL) {
            nodeL = nodeL->next;
            nodeR = nodeR->next->next;
        }
        
        return nodeL;
    }
};

