func canCompleteCircuit(gas []int, cost []int) int {
	total, pre, start := 0, 0, 0
	for i := 0; i < len(gas); i++ {
		total += gas[i] - cost[i]
		if pre < 0 {
			start = i
			pre = gas[i] - cost[i]
		} else {
			pre += gas[i] - cost[i]
		}
	}
	if total < 0 {
		return -1
	}
	return start
}