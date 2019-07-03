// 递增栈，当遇到大的数字直接进栈，而当遇到小于栈顶元素的数字时，就要取出栈顶元素进行处理
// 取出的顺序就是从高板子到矮板子了，于是乎遇到的较小的数字只是一个触发，表示现在需要开始计算矩形面积了
// 为了使得最后一块板子也被处理，这里用了个小trick，在高度数组最后面加上一个0，这样原先的最后一个板子也可以被处理了
// 由于栈顶元素是矩形的高度，那么关键就是求出来宽度，那么跟之前一样，单调栈中不能放高度，而是需要放坐标。
// 由于我们先取出栈中最高的板子，那么就可以先算出长度为1的矩形面积了，然后再取下一个板子，此时根据矮板子的高度算长度为2的矩形面积，以此类推，直到数字大于栈顶元素为止，再次进栈

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