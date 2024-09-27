
package main
import (
    "bufio"
    "fmt"
    "os"
)


func isLucky(str string) bool {
	return (str[0] + str[1] + str[2] == str[3] + str[4] + str[5]);
}


func main() {
    number, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isLucky( number[:len(number)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
