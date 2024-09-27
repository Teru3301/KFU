package main
import "fmt"

const rows int = 9
const cols int = 9

// Ваш код будет вставлен сюда

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
