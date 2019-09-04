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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode *even = nullptr, *oddH = head->next, *odd = nullptr, *cur = head;
        int i = 0;
        while(cur) {
            if(i % 2 == 1) {
                if(!odd) {
                    odd = cur;
                }
                else {
                    odd->next = cur;
                    odd = odd->next;
                }
            }
            else {
                if(!even) {
                    even = cur;
                }
                else {
                    even->next = cur;
                    even = even->next;
                }
            }
            cur = cur->next;
            ++i;
        }
        if(odd) odd->next = nullptr;
        even->next = oddH;
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode *odd = head, *even = head->next, *evenH = even;
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next= evenH;
        return head;
    }
};