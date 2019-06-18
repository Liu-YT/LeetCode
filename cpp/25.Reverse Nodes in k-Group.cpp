
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
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head == NULL)	return head;
        queue<int> q;
        stack<ListNode *> s;
        ListNode * cur = head;
    	int cnt = 0;
    	while(cur != NULL) {
    		while(cnt < k && cur) {
    			s.push(cur);
    			q.push(cur->val);
    			cur = cur->next;
    			cnt++;
    		}	
    		if(cnt < k)	break;
    		while(s.size()) {
    			s.top()->val = q.front();
    			s.pop();
    			q.pop();
    			cnt = 0;
    		}
    	}
    	return head;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head == NULL)	return head;
    	int cnt = 0;
    	ListNode* h = head;
    	while(cnt < k && h)	{ 
    		h = h->next;
    		++cnt;
    	}        

    	if(cnt == k) {
    		ListNode* next = reverseKGroup(h, k);
    		while(cnt--) {
    			ListNode* temp = head->next;
    			head->next = next;
    			next = head;
    			head = temp;
    		}
    		head = next;
    	}

    	return head;
    }
};
