/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/* solution 1 */
func pathSum(root *TreeNode, sum int) [][]int {
	var result [][]int
	if root == nil {
		return result
	}

	if root.Val == sum && root.Left == nil && root.Right == nil {
		result = append(result, []int{root.Val})
	}

	left := pathSum(root.Left, sum-root.Val)
	for _, arr := range left {
		arr = append([]int{root.Val}, arr...)
		result = append(result, arr)
	}
	right := pathSum(root.Right, sum-root.Val)
	for _, arr := range right {
		arr = append([]int{root.Val}, arr...)
		result = append(result, arr)
	}

	return result
}
