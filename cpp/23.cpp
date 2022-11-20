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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode;
        ListNode* node = head;
        
        while (list1 && list2) {
            node = node->next = new ListNode;
            
            if (list1->val < list2->val) {
                node->val = list1->val;
                list1 = list1->next;
            } else {
                node->val = list2->val;
                list2 = list2->next;
            }
        }
        
        node->next = list1 ? list1 : list2;
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return 0;
        int size = lists.size();
        
        while (size != 1) {
            for (int i = 0; i != size / 2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[size - 1 - i]);
            size -= size / 2;
        }
        
        return lists.front();
    }
};
