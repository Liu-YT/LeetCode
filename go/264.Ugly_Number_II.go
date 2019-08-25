func nthUglyNumber(n int) int {
	i, j, k := 0, 0, 0
	nums := make([]int, 0)
	nums = append(nums, 1)

	for len(nums) < n {
		a := nums[i] * 2
		if nums[j]*3 < a {
			a = nums[j] * 3
		}
		if nums[k]*5 < a {
			a = nums[k] * 5
		}
		nums = append(nums, a)
		if nums[len(nums)-1] == nums[i]*2 {
			i++
		}

		if nums[len(nums)-1] == nums[j]*3 {
			j++
		}

		if nums[len(nums)-1] == nums[k]*5 {
			k++
		}
	}

	return nums[len(nums)-1]
}