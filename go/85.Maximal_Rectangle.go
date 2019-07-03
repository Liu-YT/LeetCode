// 参考：https://blog.csdn.net/doc_sgl/article/details/11832965

func largestRectangleArea(heights []int) int {
	top, result, i := -1, 0, 0
	heights = append(heights, 0)

	// 存元素下标
	stack := make([]int, len(heights))
	for i < len(heights) {
		if top == -1 || heights[stack[top]] <= heights[i] {
			top++
			stack[top] = i
			i++
		} else {
			index := stack[top]
			num := heights[index]
			top--
			if top == -1 {
				num = num * i
			} else {
				num = num * (i - stack[top] - 1)
			}

			if num > result {
				result = num
			}
		}
	}
	return result
}

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	m, n := len(matrix), len(matrix[0])
	var dp [][]int
	for i := 0; i < m; i++ {
		dp = append(dp, make([]int, n))
	}

	for i := 0; i < n; i++ {
		if matrix[0][i] == '1' {
			dp[0][i] = 1
		}
	}

	for i := 0; i < n; i++ {
		for j := 1; j < m; j++ {
			if matrix[j][i] == '1' {
				dp[j][i] = dp[j-1][i] + 1
			}
		}
	}

	maxArea := 0
	for i := 0; i < m; i++ {
		area := largestRectangleArea(dp[i])
		if area > maxArea {
			maxArea = area
		}
	}

	return maxArea
}
