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

func solve() {
}

func main() {
	defer writer.Flush()
	var tc int
	scanf("%d", &tc)
	// tc = 1
	for ; tc>0; tc-- {
		solve()
		// writer.Flush()
	}
}
