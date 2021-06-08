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
func print(a ...interface{}) (int, error) { return fmt.Fprint(writer, a...) }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

func solve() {
	var N, M int
	scan(&N,&M)

	alist:=make([][]int, N+1)
	for i:=0;i<M;i++ {
		var a, b int
		scan(&a,&b)
		alist[a]=append(alist[a], b)
	}

	sccvis:=make([]bool, N+1)
	scclist:=make([][]int, N+1)
	idcnt:=1
	low:=make([]int, N+1)
	stk, stk_h:=make([]int, N), 0

	G:=0

	var tarj func(int)
	tarj = func(u int) {
		low[u] = idcnt
		uid := idcnt
		idcnt++

		bottom := stk_h
		stk[stk_h] = u
		stk_h++

		for _,v:=range alist[u] {
			if low[v]==0 { tarj(v) }
			if !sccvis[v] && low[u] > low[v] { low[u] = low[v] }
		}

		if low[u] != uid { return }

		scc := make([]int, stk_h-bottom)
		for i := range scc {
			v:=stk[i+bottom]
			sccvis[v] = true
			scc[i] = v
		}
		stk_h = bottom

		sort.Sort(sort.IntSlice(scc))
		scclist[G] = scc
		G++
	}
	for i:=1; i<=N; i++ {
		if(low[i]==0) { tarj(i) }
	}
	scclist = scclist[:G]
	sort.Slice(scclist, func(i, j int) bool {
		return scclist[i][0] < scclist[j][0]
	})

	println(G)
	for _, scc := range scclist {
		for _, v := range scc {
			print(v, " ")
		}
		println(-1)
	}
}

func main() {
	solve()
	writer.Flush()
}
