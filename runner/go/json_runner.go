package main

import (
	"fmt"
	"os"
	"encoding/json"
	"bufio"
	"bytes"
	"reflect"
)

type testcase struct {
	inputs [][]byte
	output []byte
}


// Decode a JSON string with help of type hint
func customUnmarshal(data []byte, v *interface{}, targetType reflect.Type) error {
	w := reflect.New(targetType).Interface()
	err := json.Unmarshal(data, w)
	if err != nil {
		return err
	}
	*v = reflect.ValueOf(w).Elem().Interface()
	return nil
}


func main() {
	var lines [][]byte
	if len(os.Args) == 1 {
		r := bufio.NewReader(os.Stdin)
		for {
			line, _ := r.ReadBytes('\n')
			n := len(line)
			if n > 0 {
				if line[n-1] == '\n' { n--; }
				lines = append(lines, line[:n])
			} else {
				break
			}
		}
	} else {
		contents, _ := os.ReadFile(os.Args[1])
		lines = bytes.Split(contents, []byte("\n"))
	}
	if len(lines[:len(lines)-1]) > 0 {
		lines = append(lines, []byte("")) // sentinel value
	}

	var (
		testcases []testcase
		tcData [][]byte
	)

	for _, line := range lines {
		if len(line) == 0 && len(tcData) > 0 {
			N := len(tcData)
			testcases = append(testcases, testcase{ tcData[:N-1], tcData[N-1] })
			tcData = nil
		} else if len(line) > 0 {
			tcData = append(tcData, line)
		}
	}

	rf_solution := reflect.ValueOf(solution)
	nArgs := rf_solution.Type().NumIn()

	for tidx, tcase := range testcases {
		fmt.Printf("# Testcase %d\n", tidx+1)
		fmt.Printf("[input]\n  ")
		fmt.Println(string(bytes.Join(tcase.inputs, []byte(", "))))
		rf_in := make([]reflect.Value, nArgs)

		for i := 0; i < nArgs; i++ {
			var v interface{}
			customUnmarshal(tcase.inputs[i], &v, rf_solution.Type().In(i))
			rf_in[i] = reflect.ValueOf(v)
		}

		rf_result := rf_solution.Call(rf_in)
		ans := rf_result[0].Interface()

		fmt.Printf("[    Your answer] %v\n", ans)
		fmt.Printf("[Expected answer] %s\n", string(tcase.output))
	}
}
