/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbers(root *TreeNode) int {
	if root == nil {
		return 0
	}

	ans := 0

	queue := make([]*TreeNode, 0)
	queue = append(queue, root)

	for len(queue) > 0 {
		front := queue[0]
		queue = queue[1:]
		if front.Left == nil && front.Right == nil {
			ans += front.Val
		}

		if front.Left != nil {
			front.Left.Val = front.Val*10 + front.Left.Val
			queue = append(queue, front.Left)
		}

		if front.Right != nil {
			front.Right.Val = front.Val*10 + front.Right.Val
			queue = append(queue, front.Right)
		}
	}

	return ans
}