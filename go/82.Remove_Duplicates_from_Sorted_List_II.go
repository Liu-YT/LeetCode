/**
// 加个头指针，使用一个指针指向头，使得操作更加统一


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

	// 消除头部重复元素
	newH := new(ListNode)
	newH.Next = head

	pre := newH

	for pre.Next != nil {
		cur := pre.Next
		for cur.Next != nil && cur.Next.Val == cur.Val {
			cur = cur.Next
		}
		if cur != pre.Next {
			pre.Next = cur.Next
		} else {
			pre = pre.Next
		}
	}

	return newH.Next
}