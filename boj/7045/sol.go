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
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

func main() {
	var N, H int
	scan(&N)
	H = N/2
	alist:=make([][]int, N)
	for i:=1; i<N; i++ {
		var u, v int
		scan(&u,&v)
		u--;v--
		alist[u]=append(alist[u], v)
		alist[v]=append(alist[v], u)
	}
	var ans []int
	szz:=make([]int, N)
	var dfs func(int,int)
	dfs=func(p, u int) {
		ok:=true
		for _,v:=range alist[u] {
			if v==p { continue }
			dfs(u,v)
			if szz[v] > H { ok=false }
			szz[u] += szz[v]
		}
		szz[u]++
		if ok && N-szz[u]<=H {
			ans=append(ans,u)
		}
	}
	dfs(-1,0)
	sort.Sort(sort.IntSlice(ans))
	for _, v:=range ans {
		println(v+1)
	}
	writer.Flush()
}
