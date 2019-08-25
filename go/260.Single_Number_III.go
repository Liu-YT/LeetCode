/* solution 1 */
func singleNumber(nums []int) []int {
	m := make(map[int]int)

	for _, val := range nums {
		if _, ok := m[val]; ok {
			m[val] = m[val] + 1
		} else {
			m[val] = 1
		}
	}

	ans := make([]int, 0)
	for key, val := range m {
		if val == 1 {
			ans = append(ans, key)
		}
	}

	return ans
}

/* solution 2 */
// https://segmentfault.com/a/1190000004886431
func singleNumber(nums []int) []int {
	// 假设结果为A，B，数组遍历取异或后的结果即为A^B
	num := 0
	for _, val := range nums {
		num = num ^ val
	}
	// fmt.Println(num)
	bitFlag := (num & (^(num - 1)))
	// fmt.Println(bitFlag)
	ans := []int{0, 0}

	for _, val := range nums {
		if val&bitFlag > 0 {
			ans[0] = ans[0] ^ val
		} else {
			ans[1] = ans[1] ^ val
		}
	}

	return ans
}