package main
import (
	"os"
	"bufio"
	"strconv"
	"bytes"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

var N int
var brd [10][10]int
type pos struct { x, y int }
var DD = [...]pos{
	{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
}

func search() {
	cnt:=0
	for i:=1; i<N-1; i++ {
		for j:=1; j<N-1; j++ {
			cur:=&brd[i][j]
			if *cur!=2 { continue }
			cnt++
			for _, e:=range DD {
				des := &brd[i+e.x][j+e.y]
				if *des!=2  { continue }
				tar := &brd[i+2*e.x][j+2*e.y]
				if *tar!=0 { continue }
				*cur, *des, *tar = 0, 0, 2
				search()
				*cur, *des, *tar = 2, 2, 0
			}
		}
	}
	if cnt==1 {
		writer.WriteString("Possible\n")
		writer.Flush()
		os.Exit(0)
	}
}

func main() {
	line,_,_:=reader.ReadLine()
	N,_=strconv.Atoi(string(line))
	for i:=0; i<N; i++ {
		line,_,_:=reader.ReadLine()
		tokens:=bytes.Fields(line)
		for j:=0; j<N; j++ {
			brd[i][j],_=strconv.Atoi(string(tokens[j]))
		}
	}
	search()
	writer.WriteString("Impossible\n")
	writer.Flush()
}
