// https://leetcode.com/articles/number-of-digit-one/
func countDigitOne(n int) int {
	cnt := 0
	for i := 1; i <= n; i *= 10 {
		divider := i * 10
		tmp := 0
		if (n%divider - i + 1) > 0 {
			tmp = (n%divider - i + 1)
		}
		if tmp > i {
			tmp = i
		}
		cnt += (n/divider)*i + tmp
	}
	return cnt
}
