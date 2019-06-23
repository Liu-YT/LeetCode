/*
 DP
 way[i] = way[i-1] + way[i-2]
*/
func climbStairs(n int) int {
    if n == 1 {
        return 1
    }
	way := make([]int, n+1)
	way[1] = 1
	way[2] = 2
	for i := 3; i <= n; i++ {
		way[i] = way[i-1] + way[i-2]
	}
	return way[n]
}