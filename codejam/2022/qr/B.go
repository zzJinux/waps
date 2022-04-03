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

func mm(a,b int) int {
	if a>b {return b}
	return a
}

func solve(tc int) {
	defer flush()
	printf("Case #%d: ",tc)
	aa,bb,cc,dd := 1000000,1000000,1000000,1000000
	for i:=0;i<3;i++{
		var a,b,c,d int
		scan(&a,&b,&c,&d)
		if aa>a {
			aa=a
		}
		if aa>a {
			aa=a
		}
		if bb>b {
			bb=b
		}
		if cc>c {
			cc=c
		}
		if dd>d {
			dd=d
		}
	}
	x:=1000000
	x-=aa
	bb=mm(x,bb)
	x-=bb
	cc=mm(x,cc)
	x-=cc
	dd=mm(x,dd)
	x-=dd
	if x>0 {
		println("IMPOSSIBLE")
	} else {
		println(aa,bb,cc,dd)
	}
}

func main() {
	var tc int
	scan(&tc)
	for i:=1; i<=tc; i++ {
		solve(i)
	}
}
