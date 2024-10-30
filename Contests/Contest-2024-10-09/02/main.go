package main

import (
	"fmt"
	"math/rand"
	"time"
)


type Cat struct {
	alive bool
}


type Box struct {
	cat Cat
	is_opend bool
}


func (box *Box) open () Cat {
	if !box.is_opend {
		generator := rand.New(rand.NewSource(time.Now().UnixNano()))
		box.cat.alive = (generator.Int63() % 2 == 0)
		box.is_opend = true
	} 
	return box.cat
}

func (cat Cat) is_alive () bool {
	return bool(cat.alive)
}



func main () {
	var b Box
	cat := b.open()
	cat2 := b.open()
	fmt.Println(cat.is_alive(), cat2.is_alive())
}


