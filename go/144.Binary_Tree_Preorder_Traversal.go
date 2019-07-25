/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
	ans := make([]int, 0)
	if root == nil {
		return ans
	}

	ans = append(ans, root.Val)
	left := preorderTraversal(root.Left)
	ans = append(ans, left...)
	right := preorderTraversal(root.Right)
	ans = append(ans, right...)
	return ans
}