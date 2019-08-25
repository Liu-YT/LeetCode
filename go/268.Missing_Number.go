func missingNumber(nums []int) int {
	size := len(nums)
	total := (size) * (size + 1) / 2
	for _, val := range nums {
		total -= val
	}
	return total
}