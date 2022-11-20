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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return NULL;
        ListNode* nodeL = head;
        ListNode* nodeR = head->next;
        
        while (nodeR->next != NULL && nodeR->next->next != NULL) {
            nodeL = nodeL->next;
            nodeR = nodeR->next->next;
        }
        nodeL->next = nodeL->next->next;
           
        return head;
    }
};

