/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	// 头指针
	newHead, left, right := new(ListNode), new(ListNode), new(ListNode)

	var l, r *ListNode

	for head != nil {
		if head.Val < x {
			if l == nil {
				left.Next = head
				l = head
			} else {
				l.Next = head
				l = l.Next
			}
		} else {
			if r == nil {
				right.Next = head
				r = head
			} else {
				r.Next = head
				r = r.Next
			}
		}
		nextH := head.Next
		head.Next = nil
		head = nextH
	}

	if left.Next == nil {
		newHead.Next = right.Next
	} else {
		newHead.Next = left.Next
		l.Next = right.Next
	}

	return newHead.Next
}