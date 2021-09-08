### Programmers, Leetcode
Go (`go`), Java (`java`)
```sh
. init.sh [pr|lc|json]

lang=<lang> # name of the language to use
sol=<sol>   # name of a solution code
ts=<inp>    # name of an input (testcases) file (If omitted, manually input)

# mkdir <name> && cd $_
# touch <sol>.<lang>
# touch <inp>

e    # edit
g    # execute
```

### BOJ, Codeforces
Go (`go`), C++ (`cpp`)
```sh. 
. init.sh [boj|cf|plain]

lang=<lang>
sol=<sol>
ts=<inp>

e
g
gen  # generate from the template
```

#### Input file format
`@@@` and `---` are separators.

```
1st case input line 0
1st case input line 1
(... more)
═════
1st case output line 0
1st case output line 1
(... more)
─────
2nd case input line 0
2nd case input line 1
(... more)
═════
2nd case output line 0
2nd case output line 1
(... more)
─────
last case input line 0
last case input line 1
(... more)
═════
last case output line 0
last case output line 1
(... more)
```
