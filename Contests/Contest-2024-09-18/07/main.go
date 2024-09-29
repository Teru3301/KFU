package main
import "fmt"

func shift(data []int, steps int) {
	steps *= -1
	steps %= 10
	if steps < 0 {
		steps += 10
	}

	for	i := 0; i < steps; i++ {
		var tmp = data[0]
		for i := 0; i < 9; i++ {
			data[i] = data[i+1]
		}
		data[9] = tmp
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
