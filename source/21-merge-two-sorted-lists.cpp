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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* parser1 = list1;
        ListNode* parser2 = list2;
        ListNode* cursor;
        ListNode* temp;
        
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        
        if (list1->val < list2->val) {
            head = list1;
        }
        else {
            head = list2;
        }
        cursor = head;
        
        while((parser1 != nullptr) && (parser2 != nullptr)) {
            if (parser1->val < parser2->val) {
                temp = parser1;
                parser1 = parser1->next;
            }
            else {
                temp = parser2;
                parser2 = parser2->next;
            }
            cursor->next = temp;
            cursor = temp;
        }
        
        if (parser1 != nullptr) {
            temp = parser1;
            cursor->next = temp;
        }
        if (parser2 != nullptr) {
            temp = parser2;
            cursor->next = temp;
        }
        
        return head;
    }
};
