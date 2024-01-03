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
    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        ListNode *c;
        int N = 1;
        ListNode *stack = new ListNode(p->val, nullptr);
        
        while (p->next != nullptr) {
            p = p->next;
            stack = new ListNode(p->val, stack);
            N++;
        }

        p = stack;
        c = head;
        
        for (int i=0; i<N; i++) {
            int cval = c->val;
            int pval = p->val;
            if (cval != pval) {
                return false;
            }
            c = c->next;
            p = p->next;
        }
        
        return true;
    }
};
