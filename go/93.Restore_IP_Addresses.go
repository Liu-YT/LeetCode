func isValid(s string) bool {
	if s == "" || (len(s) > 1 && s[0] == '0') {
		return false
	}
	count := 0
	for i := 0; i < len(s); i++ {
		count = count*10 + int(s[i]-'0')
	}
	if count > 255 {
		return false
	}
	return true
}

func restoreIpAddresses(s string) []string {
	var result []string
	if len(s) > 12 {
		return result
	}
	for i := 1; i <= len(s) && i <= 3; i++ {
		a := s[0:i]
		if !isValid(a) {
			continue
		}
		for j := 1; i+j <= len(s) && j <= 3; j++ {
			b := s[i : i+j]
			if !isValid(b) {
				continue
			}
			for k := 1; i+j+k <= len(s) && k <= 3; k++ {
				c := s[i+j : i+j+k]
				d := s[i+j+k:]
				if !isValid(c) || !isValid(d) {
					continue
				}
				result = append(result, a+"."+b+"."+c+"."+d)
				// fmt.Println(a, b, c, d)
			}
		}
	}
	return result
}