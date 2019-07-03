/* solution 1 */
func numTrees(n int) int {
	return getNum(1, n)
}

func getNum(start int, end int) int {
	if start >= end {
		return 1
	}
	cnt := 0
	for i := start; i <= end; i++ {
		left := getNum(start, i-1)
		right := getNum(i+1, end)
		cnt += left * right
	}
	return cnt
}

/* solution 2 */
func numTrees(n int) int {
	if n < 2 {
		return 1
	}

	dp := make([]int, n+1)
	dp[0] = 1
	dp[1] = 1

	for i := 2; i <= n; i++ {
		for j := 0; j < i; j++ {
			dp[i] += dp[j] * dp[i-j-1]
		}
	}
	return dp[n]
}