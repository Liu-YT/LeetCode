func minCut(s string) int {
	if len(s) <= 1 {
		return 0
	}

	size := len(s)

	// 记录[i, j]是否为回文
	var isPal [][]bool
	for i := 0; i < size; i++ {
		isPal = append(isPal, make([]bool, size))
	}

	// 记录[i, size]分割次数
	cut := make([]int, size+1)
	cut[size] = -1

	for i := size - 1; i >= 0; i-- {
		cut[i] = size
		for j := i; j < size; j++ {
			if (i == j) || (i+1 == j && s[i] == s[j]) || (i+1 < j && isPal[i+1][j-1] && s[i] == s[j]) {
				isPal[i][j] = true
				if cut[i] > cut[j+1]+1 {
					cut[i] = cut[j+1] + 1
				}
			}
		}
	}
	return cut[0]
}

