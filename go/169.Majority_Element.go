func majorityElement(nums []int) int {
	major := nums[0]
	count := 0
	for _, val := range nums {
		if count == 0 {
			count++
			major = val
			continue
		}

		if val == major {
			count++
		} else {
			count--
		}
	}
	return major
}