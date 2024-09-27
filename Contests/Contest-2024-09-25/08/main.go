package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	nums := make(map[int64]bool, (n/2 + 1))

	for i := 0; i < n; i++ {
		var tmp int64
		fmt.Scan(&tmp)
		nums[tmp] = !nums[tmp]
	}

	for key, value := range nums {
		if value {
			fmt.Println(key)
			break
		}
	}
}
