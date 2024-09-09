func isValidSudoku(bord [rows][cols]int) bool {

	for y := 0; y < rows; y++ {
		var sum int = 0
		for x := 0; x < cols; x++ {
			sum += bord[y][x]
		}
		if sum != 45 {
			return false
		}
	}
	for x := 0; x < cols; x++ {
		var sum int = 0
		for y := 0; y < rows; y++ {
			sum += bord[y][x]
		}
		if sum != 45 {
			return false
		}
	}

	return true
}
