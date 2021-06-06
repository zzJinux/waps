package main
import (
	"os"
	"bufio"
	"fmt"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func println(a ...interface{}) (int, error) { return fmt.Fprintln(writer, a...) }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

const MOD = 1000000007
func main() {
	var N int
	scan(&N)
	Q:=make([]int, 500001)
	W:=int64(0)
	for i:=0; i<N; i++ {
		var a int
		scan(&a)
		q:=&Q[a]
		v:=(MOD+W-int64(*q))%MOD
		*q=int((int64(*q)+v+1)%MOD)
		W=(W+v+1)%MOD
	}
	println(W)
	writer.Flush()
}
