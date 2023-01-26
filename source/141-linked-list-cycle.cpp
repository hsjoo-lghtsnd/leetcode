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
    bool hasCycle(ListNode *head) {
        const int visited = 0x01<<20;
        while (head) {
            if (head->next != NULL) {
                if (head->val != visited) {
                    head->val = visited;
                    head = head->next;
                    continue;
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        return false;
    }
};
