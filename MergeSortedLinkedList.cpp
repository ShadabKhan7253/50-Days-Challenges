class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if(l1->val > l2->val) {
            ListNode *temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode *res = l1;
        while(l1!=NULL && l2!=NULL) {
            ListNode *tmp = NULL;
            while(l1 != NULL && l1->val <= l2->val) {
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next = l2;

            ListNode *temp = l1;
            l1 =l2;
            l2 = temp;
        }
        return res;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1) current->next = l1;
        if (l2) current->next = l2;

        return dummy->next;
    }  
};