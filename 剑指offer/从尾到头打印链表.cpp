/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        ListNode* node = head;

        while(node != nullptr) {
            ans.push_back(node->val);
            node = node->next;
        } 

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        ListNode* node = head, *pHead = nullptr;

        while(node != nullptr) {
            ListNode* next = node->next;
            node->next = pHead;
            pHead = node;
            if(next == nullptr)
                break;
            node = next;

        }

        while(node != nullptr) {
            ans.push_back(node->val);
            node = node->next;
        }
        return ans;
    }
};