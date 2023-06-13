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
    ListNode* middleNode(ListNode* head) {
        if (head==nullptr) return nullptr;
        // search twice. 1: length, 2: middle node
        ListNode* cursor = head;
        int length = 1;
        int middle_length;

        while (cursor->next != nullptr) {
            cursor = cursor->next;
            length++;
        }

        cursor = head;
        middle_length = length/2;
        for (int i=0; i<middle_length; i++) {
            cursor = cursor->next;
        }
        return cursor;
    }
};

