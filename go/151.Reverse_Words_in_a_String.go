func reverseWords(s string) string {
	stack := make([]string, 0)
	cur := ""
	for _, c := range s {
		if c != ' ' {
			cur += string(c)
			continue
		}

		if cur != "" {
			stack = append(stack, cur)
			cur = ""
		}
	}

	if cur != "" {
		stack = append(stack, cur)
	}

	if len(stack) == 0 {
		return ""
	}

	cur = stack[len(stack)-1]

	for i := len(stack) - 2; i >= 0; i-- {
		cur += " " + stack[i]
	}

	return cur
}