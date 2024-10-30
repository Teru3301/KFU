package main

import "fmt"

// Начало вставленного кода
type Water struct {
	temp int
}

func NewWater(init_temp int) Water {
	return Water{init_temp}
}

type Teapot struct {
	temp int
}

func (t Teapot) is_boiling() bool {
	return t.temp >= 100
}
func (t *Teapot) heat_up(add_temp int) {
	t.temp += add_temp
}
func NewTeapot(water Water) Teapot {
	return Teapot(water)
}

// Конец вставленного кода

func main() {
	var temperature, count int
	fmt.Scan(&temperature, &count)

	heat := NewQueue()
	for i := 0; i < count; i++ {
		var t int
		fmt.Scan(&t)
		heat.Push(t)
	}

	water := NewWater(temperature)
	teapot := NewTeapot(water)

	for !teapot.is_boiling() {
		teapot.heat_up(heat.Pop())
	}

	for !heat.IsEmpty() {
		fmt.Print(heat.Pop(), " ")
	}
}
