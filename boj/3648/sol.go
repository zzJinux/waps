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

func solve() (done bool) {
	done=false
	var N, M int
	if _, err:=scan(&N,&M); err!=nil {
		return true
	}

	alist:=make([][]int, 2*N+1)
	for i:=0;i<M;i++ {
		var a, b, na, nb int
		scan(&a,&b)
		na,nb=a+N,b+N
		if a<0 { a,na=N-a,-a }
		if b<0 { b,nb=N-b,-b }
		alist[na]=append(alist[na], b)
		alist[nb]=append(alist[nb], a)
	}

	sccn:=make([]int, 2*N+1)
	low:=make([]int, 2*N+1)
	stk, stk_h:=make([]int, 2*N), 0
	idcnt:=1

	var tarj func(int)
	tarj = func(u int) {
		uid := idcnt; idcnt++
		low[u] = uid

		stk[stk_h]=u
		stk_h++

		for _,v:=range alist[u] {
			if low[v]==0 {
				tarj(v)
				if low[u] > low[v] { low[u] = low[v] }

			} else if sccn[v]==0 && low[u] > low[v] {
				low[u] = low[v]
			}
		}

		if low[u] != uid { return }

		for {
			stk_h--
			v:=stk[stk_h]
			sccn[v]=u
			if v == u { break }
		}
	}

	tarj(1)
	if low[N+1]!=0 {
		println("no")
		return
	}
	for i:=2; i<=2*N; i++ {
		if(low[i]==0) { tarj(i) }
	}
	for i:=2; i<=N; i++ {
		if sccn[i]==sccn[i+N] {
			println("no")
			return
		}
	}
	
	println("yes")
	return
}

func main() {
	for {
		if done:=solve(); done {
			break
		}
	}
	writer.Flush()
}
