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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* node = head;
        ListNode* prev = NULL;
        
        int index = 1;
        while (index != left) {
            prev = node;
            node = node->next;
            index++;
        }
        ListNode* beforeLeftNode = prev;
        ListNode* leftNode = node;
        
        while (index != right) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
            index++;
        }
        leftNode->next = node->next;
        node->next = prev;
        
        if (beforeLeftNode)
            beforeLeftNode->next = node;
        
        return left != 1 ? head : node;
    }
};

