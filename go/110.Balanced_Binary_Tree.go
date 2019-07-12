/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	a := getDepth(root.Left)
	b := getDepth(root.Right)

	if math.Abs(float64(a - b)) <= 1 && isBalanced(root.Left) && isBalanced(root.Right) {
		return true
	}

	return false

}

func getDepth(node *TreeNode) int {
	if node == nil {
		return 0
	}
	left := getDepth(node.Left)
	right := getDepth(node.Right)

	if left < right {
		return right + 1
	}
	return left + 1
}