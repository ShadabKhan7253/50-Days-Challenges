class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *current = dummy, *next = dummy, *prev = dummy;

        current = prev->next;
        while(current && current->next) {
            next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
            prev = current;
            current = current->next;
        }
        return dummy->next;
    }
};