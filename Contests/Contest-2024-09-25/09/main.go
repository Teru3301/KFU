package main

import (
	"fmt"
	"sort"
)

func main () {
	var n int
	var x int64

	fmt.Scan(&n, &x)

	var arr = make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	sort.SliceStable(arr, func(i, j int) bool {
    	return arr[i] < arr[j]
	})

	var a int64
	var b int64

	tmp := x / 2 + 1
	for i := 0; i < n; i++ {
		if arr[i] <= tmp {
			for j := i+1; j < n; j++ {
				if arr[i] + arr[j] == x {
					a = arr[i]
					b = arr[j]
				}
			}
		} else {
			break
		}
	}

	fmt.Print(a, b)
}
