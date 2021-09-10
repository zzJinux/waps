package main
import (
	"os"
	"bufio"
	"fmt"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func print(a ...interface{}) (int, error) { return fmt.Fprint(writer, a...) }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

func gcd(a int, b int) int {
	for b>0 {
		a,b=b,a%b
	}
	return a;
}

func flsq(x int) int {
	var lo, hi int = 0, 1<<30
	for lo < hi {
		mi := (lo+hi+1)/2;
		if mi*mi > x {
			hi = mi-1;
		} else {
			lo = mi
		}
	}
	return lo
}

func main() {
	var a, b int
	scan(&a, &b)
	n, d := flsq(b) - flsq(a), b-a
	g := gcd(n,d)
	if n == 0 {
		print(0)
	} else {
		print(n/g,"/",d/g)
	}
	writer.Flush()
}
