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
        /*
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
        */

        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        int N = v.size();

        ListNode* answer = new ListNode(v.back());
        ListNode* cursor = answer;
        for (int i=1; i<N; i++) {
            cursor->next = new ListNode(v[v.size()-i-1]);
            cursor = cursor->next;
        }
        return answer;
    }
};

