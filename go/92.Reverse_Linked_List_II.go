/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if m == n {
		return head
	}

	// 头指针
	newH := new(ListNode)
	newH.Next = head

	var preM, posM, nextN, temp *ListNode

	// 获取位置m的结点指针
	posM = newH
	for i := 0; i < m; i++ {
		preM = posM
		posM = posM.Next
	}

	// 获取位置n的结点指针
	nextN = head
	for i := 0; i < n; i++ {
		nextN = nextN.Next
	}

	// 逆序
	revH := nextN
	for posM != nextN {
		temp = posM
		posM = posM.Next
		temp.Next = revH
		revH = temp
	}

	preM.Next = revH
	return newH.Next
}