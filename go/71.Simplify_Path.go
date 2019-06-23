func simplifyPath(path string) string {
	var top int = -1
	var tmp, res string
	stack := make([]string, len(path))
	for i := 0; i < len(path); i++ {
		tmp = ""
		for i < len(path) && path[i] == '/' {
			i++
		}
		for i < len(path) && path[i] != '/' {
			tmp = tmp + string(path[i])
			i++
		}

		if tmp == ".." {
			if top >= 0 {
				top--
			}
		} else if tmp == "." {
			continue
		} else if tmp != "" {
			top++
			stack[top] = tmp
		}
	}
	for i := 0; i <= top; i++ {
		res = res + "/" + stack[i]
	}
	if top >= 0 {
		return res
	}
	return "/"
}