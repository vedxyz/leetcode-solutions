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
    // Destructive pruning approach
    bool hasCycle(ListNode* head) {
        while (head) {
            if (head->val == INT_MIN) return true;
            head->val = INT_MIN;
            head = head->next;
        }
        return false;
    }
    
    // HashSet approach
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> nodes;
        
        while (head) {
            if (nodes.count(head)) return true;
            nodes.insert(head);
            head = head->next;
        }
        return false;
    }
};

