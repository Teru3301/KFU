package main

import "fmt"

func space(i int) {
	if i < 10 {
		fmt.Print("   ")
	}
	if i > 9 && i < 100 {
		fmt.Print("  ")
	} else if i > 99 {
		fmt.Print(" ")
	}
}

func main() {
	var row int
	var col int

	fmt.Scan(&row, &col)

	fmt.Print("    |")
	for i := 1; i <= col; i++ {
		space(i)
		fmt.Print(i)
	}
	fmt.Print("\n   --")
	for i := 1; i <= col; i++ {
		fmt.Print("----")
	}
	fmt.Print("\n")

	for i := 1; i <= row; i++ {
		space(i)
		fmt.Print(i, "|")
		for j := 1; j <= col; j++ {
			space(i * j)
			fmt.Print(i * j)
		}
		fmt.Print("\n")
	}
}
