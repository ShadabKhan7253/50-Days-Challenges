class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s;
        while(head) {
            s += to_string(head->val);
            head = head->next;
        }
        for(int i=0;i< s.size()/2;i++) {
            if(s[i] != s[s.size() - 1 - i])
                return false;
            }
        return true;
    }
};
