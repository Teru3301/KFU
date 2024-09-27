package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

func isPalindrome(line string) bool {
	line = regexp.MustCompile(`[~,!,@,#,$,%,^,&,*,(,), ]`).ReplaceAllString(line, "")
	line = strings.ToLower(line)
	rline := ""
	for _, c := range line {
		rline = (string)(c) + rline
	}
	return line == rline
}

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isPalindrome(line[:len(line)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
