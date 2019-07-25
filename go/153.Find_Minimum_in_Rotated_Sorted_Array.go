func findMin(nums []int) int {
	start, end, minNum := 0, len(nums)-1, nums[0]
	for start < end {
		minNum = min(minNum, min(nums[start], nums[end]))
		mid := (start + end) / 2
		if nums[mid] < nums[end] {
			end = mid
			continue
		}
		start += 1
	}
	return minNum
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}