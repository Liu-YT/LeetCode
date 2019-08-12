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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *pre = nullptr, *cur = head, *temp;

        while(cur) {
            if(cur->next == nullptr) {
                cur->next = pre;
                head = cur;
                break;
            }
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return head;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *cur = head, *temp, *pre = nullptr;

        while(cur) {
            if(cur->next == nullptr) {
                head = cur;
            }
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return head;
    }
};


