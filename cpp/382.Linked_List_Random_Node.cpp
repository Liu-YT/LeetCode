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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        size = 0;
        this->head = head;
        while(head) {
            ++size;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ran = rand() % size;
        ListNode* cur = head;
        while(ran--) {
            cur = cur->next;
        }    
        return cur->val;
    }

private:
    int size;
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */