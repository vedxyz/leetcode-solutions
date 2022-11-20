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
    // Iterative solution
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    // Recursive double parameter solution
    ListNode* reverseList(ListNode* current, ListNode* prev = NULL) {
        if (!current) return prev;
        ListNode* next = current->next;
        current->next = prev;
        return reverseList(next, current);
    }
    
    // Recursive single parameter solution
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};

