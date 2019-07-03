/* recursive solution */

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	var result []int
	if root == nil {
		return result
	}

	if root.Left != nil {
		result = append(result, inorderTraversal(root.Left)...)
	}

	result = append(result, root.Val)

	if root.Right != nil {
		result = append(result, inorderTraversal(root.Right)...)
	}
	return result
}

/* iteratively solution */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	result := make([]int, 0)
	stack := make([]*TreeNode, 0)
	current := root
	for current != nil || len(stack) > 0 {
		for current != nil {
			stack = append(stack, current)
			current = current.Left
		}
		current = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		result = append(result, current.Val)
		current = current.Right
	}
	return result
}