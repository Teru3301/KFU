package main
import (
    "bufio"
    "fmt"
    "os"
)

// Ваш код будет вставлен сюда
import "strings"

func isPalindrome(line string) bool {
	line = strings.ToLower(line)

	for i := 0; i < 'a'; i++ {
		line = strings.ReplaceAll(line, (string)(i), "")
	}
    for i := 'z' + 1; i <= 255; i++ {
		line = strings.ReplaceAll(line, (string)(i), "")
	}

	var ln = len(line) - 1

	for i := 0; i < (len(line) / 2); i++ {
		if line[i] != line[ln-i] {
			return false
		}
	}

	return true
}


func main() {
    line, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isPalindrome( line[:len(line)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
