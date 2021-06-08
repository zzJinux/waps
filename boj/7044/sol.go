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
func flush() { writer.Flush() }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

type E struct {
	u, v, w int;
}
type ESorter []E
func (e *ESorter) Len() int {
	return len(*e)
}
func (e *ESorter) Swap(i, j int) {
	(*e)[i],(*e)[j]=(*e)[j],(*e)[i]
}
func (e *ESorter) Less(i, j int) bool {
	return (*e)[i].w>(*e)[j].w
}

func main() {
	var N, M int
	scan(&N,&M)
	ee := make([]E, M)
	for i:=range ee {
		scan(&ee[i].u,&ee[i].v,&ee[i].w)
	}
	eesort:=ESorter(ee)
	sort.Sort(&eesort)

	par:=make([]int, N+1)
	for i:=1;i<=N;i++ { par[i]=i }
	find:=func(x int) int {
		t:=x
		for t!=par[t] { t=par[t] }
		for par[x]!=x {
			x,par[x]=par[x],t
		}
		return t
	}
	merge:=func(x, y int) {
		par[find(x)]=find(y);
	}

	ans:=0
	cnt:=0
	for _, e:=range ee {
		if find(e.u) == find(e.v) { continue }
		ans+=e.w
		merge(e.u, e.v)
		cnt++
	}
	if cnt!=N-1 {
		println(-1)
	} else {
		println(ans)
	}
	writer.Flush()
}
