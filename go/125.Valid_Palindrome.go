import "strings"

func isPalindrome(s string) bool {
	i, j := 0, len(s)-1
	s = strings.ToUpper(s)
	for i <= j {
		for i < len(s) && !(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9') == true {
			i++
		}
		for j >= 0 && !(s[j] >= 'A' && s[j] <= 'Z' || s[j] >= '0' && s[j] <= '9') == true {
			j--
		}

		if i >= j {
			return true
		}

		if s[i] == s[j] {
			i++
			j--
		} else {
			return false
		}
	}
	return true
}