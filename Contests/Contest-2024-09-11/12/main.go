package main

import "fmt"

func main() {
	var x int
	var counter int

	fmt.Scan(&x)

	for x != 1 {
		counter++
		if x%2 == 0 {
			x /= 2
		} else {
			x = x*3 + 1
		}
	}

	fmt.Print(counter)
}
