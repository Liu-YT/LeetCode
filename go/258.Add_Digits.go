func addDigits(num int) int {
	for num >= 10 {
		cur := 0
		for num > 0 {
			cur = cur + num%10
			num = num / 10
		}
		num = cur
	}
	return num
}