func partition(s string) [][]string {
	var res [][]string
	if len(s) == 0 {
		return append(res, []string{})
	}
	for i := 0; i < len(s); i++ {
		if isPalindrome(s[:i+1]) == true {
			for _, list := range partition(s[i+1:]) {
				list = append([]string{s[0 : i+1]}, list...)
				res = append(res, list)
			}
		}
	}
	return res
}

func isPalindrome(s string) bool {
	i, j := 0, len(s)-1
	for i <= j {
		if s[i] != s[j] {
			return false
		}
		j--
		i++
	}
	return true
}