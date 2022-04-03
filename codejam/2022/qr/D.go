package main
import (
	"os"
	"bufio"
	"unsafe"
	"fmt"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) (int, error) { return fmt.Fprintf(writer, f, a...) }
func flush() { writer.Flush() }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

var b_fun = make([]int, 0, 100001)
var b_chdsum = make([]int, 0, 100001)
var b_chdmin = make([]int, 0, 100001)
var b_deg = make([]int, 0, 100001)
var b_par = make([]int, 0, 100001)
var b_ready = make([]int, 0, 100000)

func solve(tc int) {
	defer flush()
	var ans int
	printf("Case #%d: ", tc)
	
	var N int
	scan(&N)
	fun := b_fun[:N+1]
	chdsum := b_chdsum[:N+1]
	chdmin := b_chdmin[:N+1]
	deg := b_deg[:N+1]
	par := b_par[:N+1]
	ready := b_ready[:0]

	for i:=0;i<=N;i++ {
		chdsum[i]=0
		chdmin[i]=0x7fFFffFFffFFffFF
		deg[i]=0
	}

	fun[0]=0
	for i:=range fun[1:] {
		scan(&fun[i+1])
	}

	for i:=range deg[1:] {
		var p int
		scan(&p)
		par[i+1]=p
		deg[p]++
	}

	for v,d:=range deg {
		if d==0 {
			ready = append(ready,v)
			chdmin[v] = 0
		}
	}

	for {
		l:=0

		for _,u:=range ready {
			if u==0 {
				printf("%d\n",ans+chdsum[u])
				return
			}
			ans += chdsum[u] - chdmin[u]
			if fun[u] < chdmin[u] {
				fun[u] = chdmin[u]
			}
			
			p:=par[u]
			chdsum[p] += fun[u]
			if chdmin[p] > fun[u] {
				chdmin[p] = fun[u]
			}
			deg[p]--
			if deg[p]==0 {
				ready[l] = p
				l++
			}
		}

		ready = ready[:l]
	}
}

func main() {
	var tc int
	scan(&tc)
	for i:=1; i<=tc; i++ {
		solve(i)
	}
}
