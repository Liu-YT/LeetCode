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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* node = pHead, *pre = nullptr;

        while(node) {
            ListNode* next = node->next;
            node->next = pre;
            if(next == nullptr)
                break;
            pre = node;
            node = next;
        }

        return node;
    }
};