package main
import (
	"os"
	"bufio"
	"fmt"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func print(a ...interface{}) (int, error) { return fmt.Fprint(writer, a...) }
func println(a ...interface{}) (int, error) { return fmt.Fprintln(writer, a...) }
func printf(f string, a ...interface{}) (int, error) { return fmt.Fprintf(writer, f, a...) }
func flush() { writer.Flush() }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }
func scanln(a ...interface{}) (int, error) { return fmt.Fscanln(reader, a...) }
func scanf(f string, a ...interface{}) (int, error) { return fmt.Fscanf(reader, f, a...) }

func solve(tc int) {
	defer flush()
}

func main() {
	var tc int
	scanf(&tc)
	for i:=1; i<=tc; i++ {
		solve(i)
	}
}
