package main
import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	w,a := 0,N
	for ; a/10!=0; a/=10 {
		w+=9
	}
	for i:=N-w-a; i<N; i++ {
		w:=0
		for a:=i; a!=0; a/=10 {
			w+=a%10
		}
		if i+w == N {
			fmt.Print(i)
			return
		}
	}
	fmt.Print(0)
}
