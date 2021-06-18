package main
import (
	"os"
	"bufio"
	"fmt"
	"sort"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func print(a ...interface{}) (int, error) { return fmt.Fprint(writer, a...) }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

var a []int

func pr(i int) int {
	v:=a[i]
	for ; a[i]==v; i++ { print(v, " ") }
	return i
}

func main() {
	defer writer.Flush()
	var N int
	scan(&N)
	a = make([]int, N+1)
	a[N]=-1
	for i:=0; i<N; i++ { scan(&a[i]) }
	sort.IntSlice(a[:N]).Sort()

	s1,s2:=-1,-1
	i:=0
	for i<N {
		v:=a[i]
		if s1==-1 {
			s1=i
			i++; for v==a[i] { i++ }
		} else if s2==-1 {
			if a[s1]+1 != v {
				pr(s1)
				s1=-1
			} else {
				s2=i
				i++; for v==a[i] { i++ }
			}
		} else {
			pr(s1)
			print(v, " "); i++
			s1,s2 = s2,-1
		}
	}
	if s2 != -1 {
		pr(s2)
		pr(s1)
	} else if s1 != -1 {
		pr(s1)
	}
}
