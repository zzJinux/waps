package main
import (
	"os"
	"bufio"
	"fmt"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func println(a ...interface{}) (int, error) { return fmt.Fprintln(writer, a...) }
func printf(f string, a ...interface{}) (int, error) { return fmt.Fprintf(writer, f, a...) }
func flush() { writer.Flush() }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

var a1 = "..+-+-+-+-+-+-+-+-+-+"
var a2 = "..|.|.|.|.|.|.|.|.|.|"
var a3 = "+-+-+-+-+-+-+-+-+-+-+"
var a4 = "|.|.|.|.|.|.|.|.|.|.|"

func solve(tc int) {
	defer flush()
	printf("Case #%d:\n", tc)
	var R, C int
	scan(&R,&C)

	
	println(a1[:2*C+1])
	println(a2[:2*C+1])
	for i:=1;i<R;i++  {
		println(a3[:2*C+1])
		println(a4[:2*C+1])
	}
	println(a3[:2*C+1])
}

func main() {
	var tc int
	scan(&tc)
	for i:=1; i<=tc; i++ {
		solve(i)
	}
}
