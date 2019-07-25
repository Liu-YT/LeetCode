/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
	ans := make([]int, 0)
	if root == nil {
		return ans
	}

	left := postorderTraversal(root.Left)
	ans = append(ans, left...)

	right := postorderTraversal(root.Right)
	ans = append(ans, right...)

	ans = append(ans, root.Val)

	return ans
}