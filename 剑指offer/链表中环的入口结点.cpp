/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead->next == nullptr || pHead->next->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = pHead->next, *fast = pHead->next->next;

        while(slow != fast && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        else {
            slow = pHead;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return fast;
        }
    }
};