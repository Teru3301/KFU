package main

import (
	"fmt"
)

func main() {
	var n int
	var arr []float64

	fmt.Scan(&n)
	arr = make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	fmt.Print(arr[0], " ")
	for i := 1; i < n-1; i++ {
		fmt.Print(float64((arr[i-1]+arr[i]+arr[i+1])/3), " ")
	}
	fmt.Print(arr[n-1])
}
