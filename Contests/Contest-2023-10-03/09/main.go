package main

import "fmt"

func main() {
	var n int
	var x int64
	fmt.Scan(&n, &x)

	nums := make(map[int64]bool, n)
	for i := 0; i < n; i++ {
		var tmp int64
		fmt.Scan(&tmp)
		if tmp <= x {
			nums[tmp] = true
		}
	}

	var prin = true
	for key := range nums {
		if nums[x-key] {
			if x-key != key {
				fmt.Print(min(x-key, key), max(x-key, key))
				prin = false
				break
			}
		}
	}
	if prin {
		fmt.Print(0, 0)
	}
}
