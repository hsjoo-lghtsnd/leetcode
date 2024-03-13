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
        ListNode *c = head;

        while (p && p->next) {
            p = p->next->next;
            c = c->next;
        }

        if (p && !(p->next)) {
            c = c->next;
        }

        p = head;

        ListNode *prev = nullptr;
        ListNode *temp = nullptr;
        while (c && c->next) {
            temp = c->next;
            c->next = prev;
            prev = c;
            c = temp;
        }
        if (c && !(c->next)) {
            c->next = prev;
        }

        while (c && p) {
            if (c->val != p->val) {
                return false;
            }
            p = p->next;
            c = c->next;
        }
        
        return true;
    }
};
