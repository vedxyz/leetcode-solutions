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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultHead, *node;
        resultHead = node = new ListNode;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            node = node->next = new ListNode;
            
            node->val += l1 ? l1->val : 0;
            node->val += l2 ? l2->val : 0;
            node->val += carry;
            
            carry = node->val > 9 ? 1 : 0;
            if (carry) node->val %= 10;
            
            l1 = l1 ? l1->next : 0;
            l2 = l2 ? l2->next : 0;
        }
        
        return resultHead->next;
    }
};

