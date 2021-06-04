package main
import (
	"os"
	"bufio"
	"fmt"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }
func readline() (string, error) { return reader.ReadString('\n') }

type S struct {
	z, o, b int;
}
func solve() {
	var s string
	scanf("%s\n", &s)
	N := len(s)
	dd := make([]S, N+1)
	dd[0] = S{0, 0, 0}
	for i:=1; i<=N; i++ {
		switch s[i-1] {
		case '0':
			dd[i].z = dd[i-1].o + 1
			dd[i].o = 0
			dd[i].b = 0
		case '1':
			dd[i].z = 0
			dd[i].o = dd[i-1].z + 1
			dd[i].b = 0
		default:
			dd[i].z = dd[i-1].o + 1
			dd[i].o = dd[i-1].z + 1
			dd[i].b = dd[i-1].b + 1
		}
	}
	var ans int64 = 0
	for i:=1; i<=N; i++ {
		ans += int64(dd[i].z + dd[i].o - dd[i].b)
	}
	printf("%d\n", ans)
}

func main() {
	// defer writer.Flush()
	var tc int
	scanf("%d\n", &tc)
	// tc = 1
	for ; tc>0; tc-- {
		solve()
		writer.Flush()
	}
}
