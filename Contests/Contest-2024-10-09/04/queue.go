package main

type Queue []int

func (self *Queue) Push(x int) {
	*self = append(*self, x)
}

func (self *Queue) IsEmpty() bool {
	return len(*self) == 0
}

func (self *Queue) Pop() int {
	h := *self
	var el int
	l := len(h)
	el, *self = h[0], h[1:l]
	return el
}

func NewQueue() *Queue {
	return &Queue{}
}
