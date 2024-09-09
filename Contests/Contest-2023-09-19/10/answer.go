func shift(data []int, steps int) {

	steps *= -1

	for steps < 0 {
		steps += 10
	}

	for steps > 9 {
		steps -= 10
	}

	var tmp [10]int
	for i := 0; i < 10; i++ {
		tmp[i] = data[i]
	}

	for i := range data {
		if i+steps >= 10 {
			data[i] = tmp[i+steps-10]
		} else {
			data[i] = tmp[i+steps]
		}
	}
}
