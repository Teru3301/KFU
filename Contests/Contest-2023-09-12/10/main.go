package main

import "fmt"

func main() {
	var a string
	var b string
	var c string
	var q1 bool = false
	var q2 bool = false
	var q3 bool = false

	fmt.Scan(&a, &b, &c)

	if a == "Да" {
		q1 = true
	}
	if b == "Да" {
		q2 = true
	}
	if c == "Да" {
		q3 = true
	}

	if q1 {
		if q2 {
			if q3 {
				fmt.Print("Утка")
			} else {
				fmt.Print("Пингвин")
			}
		} else {
			if q3 {
				fmt.Print("Плезиозавры")
			} else {
				fmt.Print("Дельфин")
			}
		}
	} else {
		if q2 {
			if q3 {
				fmt.Print("Страус")
			} else {
				fmt.Print("Курица")
			}
		} else {
			if q3 {
				fmt.Print("Жираф")
			} else {
				fmt.Print("Кот")
			}
		}
	}
}
