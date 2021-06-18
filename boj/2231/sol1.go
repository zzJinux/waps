package main
import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	m := 0
	for i:=1; i<N; i++ {
		m++
		for r:=10; i%r==0; r*=10 {
			m -= 9
		}
		if i+m == N {
			fmt.Print(i)
			return
		}
	}
	fmt.Print(0)
}
