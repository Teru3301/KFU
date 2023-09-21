package main

import "fmt"

func main() {
	var a int
	var b int
	var c int

	fmt.Scan(&a, &b, &c)

	if a > b && a > c {
		fmt.Print(a)
	}
	if b > a && b > c {
		fmt.Print(b)
	}
	if c > a && c > b {
		fmt.Print(c)
	}
}
