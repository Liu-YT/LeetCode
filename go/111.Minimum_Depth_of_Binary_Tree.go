/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := minDepth(root.Left)
	right := minDepth(root.Right)
	if root.Left != nil && root.Right != nil {
		if left < right {
			return left + 1
		}
		return right + 1
	} else if root.Left == nil {
		return right + 1
	} else {
		return left + 1
	}
}