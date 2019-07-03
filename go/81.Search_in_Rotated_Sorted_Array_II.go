// 暴力搜索，竟然过了
func search(nums []int, target int) bool {
	for _, val := range nums {
		if val == target {
			return true
		}
	}
	return false
}

// 二分
func search(nums []int, target int) bool {
	left, right := 0, len(nums)-1
	for left <= right {
		// 消除重复元素
		for left+1 <= right && nums[left] == nums[left+1] {
			left++
		}
		for right-1 >= left && nums[right] == nums[right-1] {
			right--
		}

		mid := (left + right) / 2
		if nums[mid] == target {
			return true
		}

		if nums[mid] <= nums[right] {
			// [mid, right] 有序
			if nums[mid] < target && nums[right] >= target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		} else {
			// [left...mid...max_pos],[max_pos+1, right]有序
			if nums[left] <= target && nums[mid] > target {
				right = mid - 1
			} else {
				left = mid + 1
			}
		}
	}

	return false
}