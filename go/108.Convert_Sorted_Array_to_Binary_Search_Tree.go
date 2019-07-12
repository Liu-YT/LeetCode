/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/* solution 1 */
func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	return build(0, len(nums)-1, nums)
}

func build(start int, end int, nums []int) *TreeNode {
	if start > end {
		return nil
	}

	mid := (start + end + 1) / 2
	node := new(TreeNode)
	node.Val = nums[mid]
	node.Left = build(start, mid-1, nums)
	node.Right = build(mid+1, end, nums)
	return node
}

/* solution 2 */
func sortedArrayToBST(nums []int) *TreeNode {
	if 0 == len(nums) {
		return nil
	}
	i := len(nums) >> 1
	node := &TreeNode{Val: nums[i]}
	node.Left = sortedArrayToBST(nums[:i])
	node.Right = sortedArrayToBST(nums[i+1:])
	return node
}