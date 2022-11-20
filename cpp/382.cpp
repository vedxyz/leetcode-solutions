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
    vector<int> list;
    ListNode* head;
public:
    Solution(ListNode* head) : head(head) {
        while (head) {
            list.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        float random = ((float) rand() / RAND_MAX) * list.size();
        return list[random];
    }
    
    int getRandomReservoir() {
        int i = 1, chosen = 0;
        ListNode* node = head;
        while (node) {
            if (rand() % i++ == 0)
                chosen = node->val;
            node = node->next;
        }
        return chosen;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
