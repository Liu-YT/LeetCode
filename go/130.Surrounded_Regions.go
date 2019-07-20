func solve(board [][]byte) {
	if len(board) <= 2 {
		return
	}

	m, n := len(board), len(board[0])
	queue := make([]int, 0)

	var check [][]bool
	for i := 0; i < m; i++ {
		check = append(check, make([]bool, n))
	}

	// up
	for i := 0; i < n; i++ {
		if board[0][i] == 'O' {
			queue = append(queue, 0*n+i)
		}
	}

	// down
	for i := 0; i < n; i++ {
		if board[m-1][i] == 'O' {
			queue = append(queue, (m-1)*n+i)
		}
	}

	// left
	for i := 0; i < m; i++ {
		if board[i][0] == 'O' {
			queue = append(queue, i*n)
		}
	}

	// right
	for i := 0; i < m; i++ {
		if board[i][n-1] == 'O' {
			queue = append(queue, i*n+n-1)
		}
	}

	for len(queue) > 0 {
		front := queue[0]
		queue = queue[1:]
		i, j := front/n, front%n
		check[i][j] = true
		if i-1 >= 0 && check[i-1][j] == false && board[i-1][j] == 'O' {
			queue = append(queue, (i-1)*n+j)
		}
		if i+1 < m && check[i+1][j] == false && board[i+1][j] == 'O' {
			queue = append(queue, (i+1)*n+j)
		}
		if j-1 >= 0 && check[i][j-1] == false && board[i][j-1] == 'O' {
			queue = append(queue, i*n+j-1)
		}
		if j+1 < n && check[i][j+1] == false && board[i][j+1] == 'O' {
			queue = append(queue, i*n+j+1)
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if check[i][j] == false {
				board[i][j] = 'X'
			}
		}
	}
}