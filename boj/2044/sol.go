package main
import (
	"os"
	"bufio"
	"fmt"
	"strings"
	"sort"
)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func println(a ...interface{}) (int, error) { return fmt.Fprintln(writer, a...) }
func scan(a ...interface{}) (int, error) { return fmt.Fscan(reader, a...) }

var M, N int
type Rect struct {
	w, h int
}
var names []string
var wnds = make(map[string]Rect)
var ff [100]string
var jeom [100]byte

func main() {
	for i:=0; i<100; i++ {
		jeom[i] = '.'
	}
	defer writer.Flush()

	scan(&M,&N)
	var line string
	for i:=0; i<M; i++ {
		scan(&line)
		var ofs int
		for {
			IB := strings.IndexByte
			var jl, je int

			jl = IB(line[ofs:], '+')
			if jl == -1 {
				break
			}
			jl += ofs
			je = IB(line[jl+1:], '+') + (jl+1)
			seg := line[jl:je+1]
			ofs = je+1

			s := IB(seg, '|')
			if s == -1 {
				name := ff[jl]
				ff[jl] = ""
				_v := wnds[name]
				_v.h += i+1
				wnds[name] = _v
				continue
			}
			seg = seg[s+1:]
			name := seg[:IB(seg, '|')]

			names = append(names, name)
			wnds[name] = Rect{ je-jl+1, -i }
			ff[jl] = name
		}
	}

	sort.Sort(sort.Reverse(sort.StringSlice(names)))

	screen := make([][]byte, M)
	for i := range screen {
		screen[i] = make([]byte, N)
		copy(screen[i], jeom[:N])
	}
	cover := make([][]bool, M)
	for i := range screen {
		cover[i] = make([]bool, N)
	}

	W := len(names)
	for _q, name := range names {
		q := W-1-_q
		_r := wnds[name]
		w, h := _r.w, _r.h

		draw := func(i, j int, a byte) {
			if !cover[i][j] {
				screen[i][j] = a
			}
		}

		draw(q, q, '+')
		draw(q+(h-1), q, '+')
		draw(q, q+(w-1), '+')
		draw(q+(h-1), q+(w-1), '+')
		for j:=1; j<w-1; j++ {
			screen[q][q+j] = '-'
			draw(q+(h-1), q+j, '-')
		}
		for i:=1; i<h-1; i++ {
			draw(q+i, q, '|')
			draw(q+i, q+(w-1), '|')
		}

		s := (w - (len(name)+2))/2
		e := s+1+len(name)

		screen[q][q+s] = '|'
		copy(screen[q][q+s+1:q+e], []byte(name))
		screen[q][q+e] = '|'

		for i:=0; i<h; i++ {
			for j:=0; j<w; j++ {
				cover[q+i][q+j] = true
			}
		}
	}

	for i:=0; i<M; i++ {
		println(string(screen[i]))
	}
}
