/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	a, b, flag := headA, headB, false
	for a != b {
		if a.Next == nil {
			if flag == false {
				a = headB
				flag = true
			} else {
				return nil
			}

		} else {
			a = a.Next
		}

		if b.Next == nil {
			b = headA
		} else {
			b = b.Next
		}
	}

	return a
}