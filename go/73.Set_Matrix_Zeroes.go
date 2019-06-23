func setZeroes(matrix [][]int) {
	m, n := len(matrix), len(matrix[0])
	// 记录第0列和第0行是否有0
	var col0_has_0, row0_has_0 bool
	for _, val := range matrix[0] {
		if val == 0 {
			row0_has_0 = true
			break
		}
	}

	for _, row := range matrix {
		if row[0] == 0 {
			col0_has_0 = true
			break
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][j] == 0 {
				matrix[i][0] = 0
				matrix[0][j] = 0
			}
		}
	}

	for i := 1; i < m; i++ {
		if matrix[i][0] == 0 {
			for j := 1; j < n; j++ {
				matrix[i][j] = 0
			}
		}
	}

	for i := 1; i < n; i++ {
		if matrix[0][i] == 0 {
			for j := 1; j < m; j++ {
				matrix[j][i] = 0
			}
		}
	}

	if col0_has_0 {
		for i := 0; i < m; i++ {
			matrix[i][0] = 0
		}
	}

	if row0_has_0 {
		for i := 0; i < n; i++ {
			matrix[0][i] = 0
		}
	}
}