/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/* solution 1 */
// 暴力检索两遍，第一遍存储节点，第二遍比较
func isPalindrome(head *ListNode) bool {
	stack := make([]int, 0)
	node := head

	for node != nil {
		stack = append(stack, node.Val)
		node = node.Next
	}

	node = head
	top := len(stack) - 1
	for node != nil {
		if node.Val != stack[top] {
			return false
		}
		top--
		node = node.Next
	}
	return true
}

/* solution 2 */
// 利用快慢指针，同时反转前半部分
func isPalindrome(head *ListNode) bool {
	slow, fast := head, head
	var pre *ListNode

	for fast != nil && fast.Next != nil {

		fast = fast.Next.Next

		// 反转前半部分
		next := slow.Next
		slow.Next = pre
		pre = slow
		slow = next
	}

	if fast != nil && fast.Next == nil {
		slow = slow.Next
	}

	for pre != nil {
		if pre.Val != slow.Val {
			return false
		}
		pre = pre.Next
		slow = slow.Next
	}
	return true
}