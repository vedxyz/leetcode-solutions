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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> digits;
        ListNode* node = head;
        int carry = 1;
        
        while (node) {
            digits.push(node);
            node = node->next;
        }
        
        while (!digits.empty()) {
            digits.top()->val += carry;
            carry = digits.top()->val > 9 ? 1 : 0;
            digits.top()->val %= 10;
            digits.pop();
            
            if (carry == 0) break;
        }
        
        return carry ? new ListNode(carry, head) : head;
    }
};

