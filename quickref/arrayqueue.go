package main

import "reflect"

// This is a simple implementation of integer queue

type Queue struct {
	arr []int
	begin, end, size int
}
func (q *Queue) Init(capacity int) {
	q.arr = make([]int, capacity)
	q.begin, q.end, q.size = 0, 0, 0
}
func (q *Queue) Size() int {
	return q.size
}
func (q *Queue) Push(v int) {
	if q.size == len(q.arr) {
		panic("push: queue is full!")
	}
	q.arr[q.end] = v
	q.size++
	q.end++
	if q.end == len(q.arr) {
		q.end = 0
	}
}
func (q *Queue) Pop() int {
	if q.size == 0 {
		panic("pop: queue is empty!")
	}
	v := q.arr[q.begin]
	q.size--
	q.begin++
	if q.begin == len(q.arr) {
		q.begin = 0
	}
	return v
}
func (q *Queue) Peek() int {
	if q.size == 0 {
		panic("peek: queue is empty!")
	}
	return q.arr[q.begin]
}

func assertPanic(f interface{}, message string) {
	defer func() {
		if r := recover(); r == nil {
			panic("panic not happened: " + message)
		}
	}()
	reflect.ValueOf(f).Call(nil)
	// f()
}

func testtest() {
	defer func() {
		if r := recover(); r != nil {
			panic("test fail: " + r.(string))
		}
	}()

	var q Queue
	q.Init(10)
	assertPanic(q.Peek, "(1) peek")
	assertPanic(q.Pop, "(1) pop")

	for i:=0; i<10; i++ {
		q.Push(i)
	}
	assertPanic(func() { q.Push(100) }, "(1) push")
	if q.Size() != 10 {
		panic("(1) size wrong")
	}

	for i:=0; i<10; i++ {
		if i != q.Pop() {
			panic("(1) pop wrong")
		}
	}
	if q.Size() != 0 {
		panic("(2) size wrong")
	}
	assertPanic(q.Peek, "(2) peek")
	assertPanic(q.Pop, "(2) pop")

	for i:=0; i<10; i++ {
		q.Push(i)
	}
	if q.Size() != 10 {
		panic("(3) size wrong")
	}
	assertPanic(func() { q.Push(100) }, "(2) push")

	for i:=0; i<55; i++ {
		q.Push(q.Pop())
	}
	if q.Size() != 10 {
		panic("(4) size wrong")
	}
	assertPanic(func() { q.Push(100) }, "(3) push")

	for i:=0; i<5; i++ {
		if i+5 != q.Pop() {
			panic("(2) pop wrong")
		}
	}
	if q.Size() != 5 {
		panic("(5) size wrong")
	}

	for i:=0; i<5; i++ {
		if i != q.Pop() {
			panic("(3) wrong result")
		}
	}
	if q.Size() != 0 {
		panic("(6) size wrong")
	}
	assertPanic(q.Peek, "(3) peek")
	assertPanic(q.Pop, "(3) pop")
}

func main() {
	testtest()
}
