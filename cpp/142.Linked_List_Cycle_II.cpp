/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 思路依旧是快慢指针，快指针每次移动两个，慢指针一个
// 当快慢指针相遇，存在以下等式
//  2(x+y) = x+2y+z，其中x表示起点到环路入口，y表示快慢指针相遇逆时针距环路入口，z表示到顺时针到环路入口
// 等式可以推到出x=z
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(slow && fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        
        // 不存在环
        if(!fast || !fast->next) {
            return nullptr;
        }

        fast = head;
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};