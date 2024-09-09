package main
import "fmt"

const rows int = 9
const cols int = 9

// Ваш код будет вставлен сюда
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


func main() {
    var bord [rows][cols]int
    
    for row:=0; row < rows; row++ {
        for col:=0; col < cols; col++ {
            fmt.Scanf("%c", &bord[row][col])  // Считываем один символ
            bord[row][col] -= '0'  // Чтобы из ASCII кода символа получить цифру
        }
        fmt.Scanf("\n")
    }
    
    if isValidSudoku(bord){
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
