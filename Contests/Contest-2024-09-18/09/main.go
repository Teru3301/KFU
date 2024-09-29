package main

import "fmt"

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

func main() {
    var rows, cols int
    fmt.Scanf("%d %d\n", &rows, &cols)
    
    // Создаём срез и заполняем его данными о расположении мин
    maze := make([][]int, rows, rows)
    for i := range maze {
        maze[i] = make([]int, cols, cols)
        for j := range maze[i] {
            fmt.Scanf("%d", &maze[i][j])
        }
    }
    
    // Заполняем игровое поле подсказками
    fill(maze)
    
    // Выводим на экран
    for _, row := range maze {
         for _, cell := range row {
             fmt.Printf("%3d", cell)
        }
        fmt.Println()
    }
}
