// 暴力破解
func mySqrt(x int) int {
	res, i := 0, 1
	for true {
		if i*i > x {
			res = i - 1
			break
		}
		i++
	}
	return res
}

// 二分法
func mySqrt(x int) int {
	l, r := 0, x
	for l < r {
		mid := (l + r) / 2
		if mid*mid <= x && (mid+1)*(mid+1) > x {
			return mid
		}

		if (mid+1)*(mid+1) == x {
			return mid + 1
		}

		if mid*mid > x {
			r = mid
		}

		if (mid+1)*(mid+1) < x {
			l = mid + 1
		}
	}
	return 0
}