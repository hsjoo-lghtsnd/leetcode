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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr) return nullptr;
        ListNode* first = head;
        ListNode* answer;
        while (head->next != nullptr) {
            if (head->next->next != nullptr) {
                head = head->next;
                continue;
            }
            else {
                break;
            }
        }
        if (head->next == nullptr) {
            return head;
        }
        else {
            answer = head->next;
            head->next=nullptr;
            answer->next = head;
            reverseList(first);
        }
        return answer;
    }
};

