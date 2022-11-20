/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        do {
            if (!fast || !fast->next) return NULL;
            
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != slow);
        
        slow = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};
