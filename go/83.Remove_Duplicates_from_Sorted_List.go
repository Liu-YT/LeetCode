/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	pre := head
	for pre.Next != nil {
		cur := pre.Next
		for cur != nil && cur.Val == pre.Val {
			cur = cur.Next
		}
		if cur != pre.Next {
			pre.Next = cur
		} else {
			pre = pre.Next
		}
	}
	return head
}