/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func hasPathSum(root *TreeNode, sum int) bool {
	if root != nil {
		if root.Val == sum && root.Left == nil && root.Right == nil {
			return true
		}
		return hasPathSum(root.Left, sum-root.Val) || hasPathSum(root.Right, sum-root.Val)
	}
	return false
}
