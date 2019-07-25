/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *pre, *slow = head, *fast = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        pre->next = nullptr;
        ListNode* a = sortList(head);
        ListNode* b = sortList(slow);
        
        head = mergeList(a, b);
        return head;
    }

    ListNode* mergeList(ListNode* a, ListNode* b) {
        if(a == nullptr)    return b;
        if(b == nullptr)    return a;

        if(a->val < b->val) {
            a->next = mergeList(a->next, b);
            return a;
        }
     
        b->next = mergeList(a, b->next);
        return b;
    }
};