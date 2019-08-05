// 滑动窗口
func minSubArrayLen(s int, nums []int) int {
	ans, left, right, sum := len(nums)+1, 0, -1, 0
	for left < len(nums) {
		if sum < s && right+1 < len(nums) {
			right++
			sum += nums[right]
		} else {
			if sum >= s && right-left+1 < ans {
				ans = right - left + 1
			}
			sum -= nums[left]
			left++
		}
	}

	if ans == len(nums)+1 {
		return 0
	}

	return ans
}