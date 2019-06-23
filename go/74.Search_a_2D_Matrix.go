func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	start, end, size := 0, len(matrix)-1, len(matrix[0])-1
	var mid, mmid int
	if matrix[0][0] > target || matrix[len(matrix)-1][len(matrix[0])-1] < target {
		return false
	}

	// 二分查找区间
	for start <= end {
		mid = (start + end) / 2
		if matrix[mid][0] > target {
			end = mid - 1
		} else if matrix[mid][size] < target {
			start = mid + 1
		} else {
			break
		}
	}

	// 二分查找是否存在
	start, end = 0, size
	for start < end {
		mmid = (start + end) / 2
		if matrix[mid][mmid] == target {
			return true
		} else if matrix[mid][mmid] > target {
			end = mmid - 1
		} else {
			start = mmid + 1
		}
	}
	return false
}