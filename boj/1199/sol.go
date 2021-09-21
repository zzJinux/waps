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

var N int
var adj [][]int
var nxt []int

func main() {
	defer writer.Flush()
	scan(&N)
	_slice := make([]int, N*N)
	adj = make([][]int, N)
	nxt = make([]int, N)

	for i:=0; i<N; i++ {
		adj[i] = _slice[i*N:i*N+N]
	}
	for i:=0; i<N; i++ {
		for j:=0; j<N; j++ {
			scan(&adj[i][j])
		}
	}

	for u:=0; u<N; u++ {
		var z int
		for v:=0; v<N; v++ {
			z += int(adj[u][v])
		}
		if z%2 == 1 {
			print(-1)
			return
		}
	}

	stk := make([]int, 0, N)
	stk = append(stk, 0)
	for len(stk) > 0 {
		u := stk[len(stk)-1]
		v := nxt[u]

		for ; v<N; v++ {
			if adj[u][v] > 0 {
				adj[u][v]--
				adj[v][u]--
				nxt[u] = v
				stk = append(stk, v)
				break
			}
		}

		if v == N {
			stk = stk[:len(stk)-1]
			print(u+1, " ")
		}
	}
}
