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

var Q, N, D int
var f1, f2 []byte
var _dp [2][201]int64
var pdp, cdp = _dp[0][:], _dp[1][:]
func main() {
	scan(&Q,&N,&D,&f1,&f2)
	pdp[0]=1
	for i:=0; i<N; i++ {
		c1, c2 := f1[i], f2[i]
		if c1==c2 {
			copy(cdp[:D+1], pdp[:D+1])

			for a:=2; a<=D; a++ {
				cdp[a]+=pdp[a-2]*int64(Q-1)
			}
		} else {
			cdp[0]=0
			for a:=1; a<=D; a++ {
				cdp[a]=pdp[a-1]*2
			}

			for a:=2; a<=D; a++ {
				cdp[a]+=pdp[a-2]*int64(Q-2)
			}
		}
		cdp, pdp = pdp, cdp
	}
	println(pdp[D])
	writer.Flush()
}
