package main
import (
    "bufio"
    "fmt"
    "os"
)

// Ваш код будет вставлен сюда
func isLucky(str string) bool {
	var num1 = str[0] + str[1] + str[2]
	var num2 = str[3] + str[4] + str[5]
	return (num1 == num2)
}


func main() {
    number, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isLucky( number[:len(number)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
