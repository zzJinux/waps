package main
import (
	"os"
	"bufio"
	"fmt"
	"sort"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func println(a ...interface{}) (int, error) { return fmt.Fprintln(writer, a...) }
func printf(f string, a ...interface{}) (int, error) { return fmt.Fprintf(writer, f, a...) }
func flush() { writer.Flush() }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

func solve(tc int) {
	defer flush()
	printf("Case #%d: ",tc)
	var N int
	var S []int
	scan(&N)
	S = make([]int, N)
	for i := range S {
		scan(&S[i])
	}
	sort.IntSlice(S).Sort()
	ans:=1
	for i:=1;i<N;i++{
		if ans<S[i] {
			ans++
		}
	}
	println(ans)
}

func main() {
	var tc int
	scan(&tc)
	for i:=1; i<=tc; i++ {
		solve(i)
	}
}
