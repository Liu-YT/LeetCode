/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// inorder
func sol(a *TreeNode, b *TreeNode) bool {
	if a == nil && b == nil {
		return true
	}
	if (a == nil && b != nil) || (a != nil && b == nil) || a.Val != b.Val {
		return false
	}

	return sol(a.Left, b.Right) && sol(a.Right, b.Left)
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return sol(root.Left, root.Right)
}