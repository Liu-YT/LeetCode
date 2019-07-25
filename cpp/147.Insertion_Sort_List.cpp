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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* last = head;
        
        while(last->next != nullptr) {
            if(last->val <= last->next->val) {
                last = last->next;
                continue;
            }

            if(last->next->val < head->val) {
                ListNode* tmp = last->next;
                last->next = tmp->next;
                tmp->next = head;
                head = tmp;
                continue;
            }

            for(ListNode* cur = head; cur != last; cur = cur->next) {
                if(last->next->val < cur->next->val) {
                    ListNode *tmp = last->next;
                    last->next = tmp->next;
                    tmp->next = cur->next;
                    cur->next = tmp;
                    break;
                }
            }
        }

        return head;
    }
};