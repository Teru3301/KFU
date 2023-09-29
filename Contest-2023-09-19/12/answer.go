func fill(maze [][]int) {
	for y := range maze {
		for x := range maze[y] {
			if maze[y][x] == 0 {
				var xy = [8][2]int{{1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}}

				for i := 0; i < 8; i++ {
					if (y+xy[i][0] < 0) || (y+xy[i][0] > len(maze)-1) || (x+xy[i][1] < 0) || (x+xy[i][1] > len(maze[y])-1) {
						continue
					}
					if maze[y+xy[i][0]][x+xy[i][1]] == -1 {
						maze[y][x]++
					}
				}
			}
		}
	}
}
