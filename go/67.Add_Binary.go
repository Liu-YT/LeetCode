func addBinary(a string, b string) string {
	maxLen := len(a)
	if len(b) > maxLen {
		maxLen = len(b)
	}

	res := make([]byte, maxLen+1)

	var add byte = 0

	for i := 1; i <= maxLen; i++ {
		var sum byte = 0
		if i <= len(a) {
			sum = a[len(a)-i] - '0'
		}
		if i <= len(b) {
			sum = sum + b[len(b)-i] - '0'
		}
		res[maxLen+1-i] = (sum+add)%2 + '0'
		add = (sum + add) / 2
	}
	if add == 1 {
		res[0] = add + '0'
		return string(res)
	}
	return string(res[1:])
}