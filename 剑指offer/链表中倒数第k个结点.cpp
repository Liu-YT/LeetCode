/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* node = pListHead;
        for(int i = 0; i < k; i++) {
            if(!node)   return nullptr;
            node = node->next;
        }

        ListNode* cur = pListHead;
        while(node != nullptr) {
            node = node->next;
            cur = cur->next;
        }

        return cur;
    }
};