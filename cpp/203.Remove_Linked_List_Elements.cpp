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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pHead = new ListNode(-1), *cur = head, *pre = pHead;
        pre->next = head;
        while(cur != nullptr) {
            if(cur->val == val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
                continue;
            }
            pre = cur;
            cur = cur->next;
        }
        head = pHead->next;
        delete pHead;
        return head;
    }
};