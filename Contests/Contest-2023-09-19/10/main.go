package main
import "fmt"

// Ваш код будет вставлен сюда
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


func main(){
    var steps int
    fmt.Scan(&steps)

    var data [10]int
    for index := range data{
        fmt.Scan(&data[index])
    }

    shift(data[:], steps);
    for _, value := range data{
        fmt.Printf("%d ", value)
    }
}
