// https://leetcode.com/problems/recover-binary-search-tree/solution/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/* solution 1 */
// 1. Construct inorder traversal.
// 2. Find swapped elements in an almost sorted array where only two elements are swapped.
// 3. Swap values of two nodes.
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

func findTwoSwapped(nums []int) (int, int) {
	x, y := -1, -1
	for i := 0; i < len(nums)-1; i++ {
		if nums[i+1] < nums[i] {
			y = nums[i+1]
			if x == -1 {
				// first swap occurence
				x = nums[i]
			} else {
				// second swap occurence
				break
			}
		}
	}
	return x, y
}

func recover(root *TreeNode, count int, x int, y int) {
	if root != nil {
		if root.Val == x {
			root.Val = y
			count--
		} else if root.Val == y {
			root.Val = x
			count--
		}
		if count == 0 {
			return
		}

		recover(root.Left, count, x, y)
		recover(root.Right, count, x, y)
	}
}

func recoverTree(root *TreeNode) {
	nums := inorderTraversal(root)
	x, y := findTwoSwapped(nums)
	recover(root, 2, x, y)
}

/* solution 2 */
func swap(a *TreeNode, b *TreeNode) {
	tmp := a.Val
	a.Val = b.Val
	b.Val = tmp
}

func recoverTree(root *TreeNode) {
	stack := make([]*TreeNode, 0)
	var a, b, pre *TreeNode = nil, nil, nil
	for len(stack) > 0 || root != nil {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}

		root = stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if pre != nil && root.Val < pre.Val {
			b = root
			if a == nil {
				a = pre
			} else {
				break
			}
		}

		pre = root
		root = root.Right
	}
	swap(a, b)
}

