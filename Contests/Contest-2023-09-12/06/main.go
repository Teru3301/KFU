package main

import "fmt"

func main() {
	var a int
	var b int
	var c int
	var d int
	var e int

	var N int

	fmt.Scan(&N)

	a = N / 5000
	N %= 5000
	b = N / 1000
	N %= 1000
	c = N / 500
	N %= 500
	d = N / 200
	N %= 200
	e = N / 100

	fmt.Print(a, b, c, d, e)

}
