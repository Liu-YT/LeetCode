/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/* solution 1 暴力解法 */
func sortedListToBST(head *ListNode) *TreeNode {
	nums := make([]int, 0)
	for head != nil {
		nums = append(nums, head.Val)
		head = head.Next
	}
	return toBST(nums)
}
func toBST(nums []int) *TreeNode {
	if 0 == len(nums) {
		return nil
	}
	i := len(nums) >> 1
	node := &TreeNode{Val: nums[i]}
	node.Left = toBST(nums[:i])
	node.Right = toBST(nums[i+1:])
	return node
}

/* solution 2 快慢指针找终点 */
func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}

	preHead := &ListNode{Next: head}
	slow, fast := preHead, preHead

	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	mid := slow.Next
	slow.Next = nil

	return &TreeNode{
		Val:   mid.Val,
		Left:  sortedListToBST(preHead.Next),
		Right: sortedListToBST(mid.Next),
	}
}