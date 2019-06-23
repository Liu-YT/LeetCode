func sortColors(nums []int) {
	color := make([]int, 3)
	for _, val := range nums {
		color[val]++
	}
	i := 0
	for j, val := range color {
		for k := 0; k < val; k++ {
			nums[i] = j
			i++
		}
	}
}