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
    void reorderList(ListNode* head) {
        if(!head)   return;
        vector<ListNode*> v;
        while(head) {
            v.push_back(head);
            head = head->next;
        }
        int size = v.size();
        for(int i = 0; i < size / 2; i++) {
            v[i]->next = v[size - i -1];
            v[size - i - 1]->next = v[i+1];
        }

        v[size / 2]->next = nullptr;

        head = v[0];
    }
};