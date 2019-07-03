import "math"

// 二叉搜索树中,左子树中的最右结点肯定是该左子树的最大值，右子树的最左结点是肯定是右子树的最小值
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
/* solution 1 */
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if root.Left != nil {
		if root.Left.Val >= root.Val {
			return false
		}
		tmp := root.Left
		for tmp.Right != nil {
			tmp = tmp.Right
		}
		if tmp.Val >= root.Val {
			return false
		}
	}
	if root.Right != nil {
		if root.Right.Val <= root.Val {
			return false
		}
		tmp := root.Right
		for tmp.Left != nil {
			tmp = tmp.Left
		}
		if tmp.Val <= root.Val {
			return false
		}
	}
	return isValidBST(root.Left) && isValidBST(root.Right)
}

/* solution 2 */
func isValidBST(root *TreeNode) bool {
	return isValidBSTHelper(root, math.MaxInt64, math.MinInt64)
}

func isValidBSTHelper(root *TreeNode, max int, min int) bool {
	if root == nil {
		return true
	}

	if root.Val <= min || root.Val >= max {
		return false
	}

	return isValidBSTHelper(root.Left, root.Val, min) && isValidBSTHelper(root.Right, max, root.Val)
}