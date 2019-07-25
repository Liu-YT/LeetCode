import "strconv"

func evalRPN(tokens []string) int {
	if len(tokens) == 0 {
		return 0
	}

	stack := make([]int, len(tokens))
	top := -1
	for _, str := range tokens {
		num, err := strconv.Atoi(str)
		if err == nil {
			top++
			stack[top] = num
			continue
		}

		num1 := stack[top-1]
		num2 := stack[top]

		if str == "+" {
			stack[top-1] = num1 + num2
		} else if str == "-" {
			stack[top-1] = num1 - num2
		} else if str == "*" {
			stack[top-1] = num1 * num2
		} else {
			stack[top-1] = num1 / num2
		}

		top -= 1
	}

	return stack[top]
}