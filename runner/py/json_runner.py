import sys, json
import importlib.machinery
solution = importlib.machinery.SourceFileLoader('solution', sys.argv[1]).load_module()

if sys.argv == 2:
    lines = sys.stdin.readlines()
else:
    with open(sys.argv[2]) as f:
        lines = f.readlines()

lines = [line.rstrip() for line in lines]
if len(lines[-1]) != 0:
    lines.append('')

# testcases[i] -> { 'in_args': [arg1, arg2, ...] 'out': }
testcases = []
tcdata = []

for line in lines:
    if len(line) > 0:
        tcdata.append(line)
    elif len(tcdata) > 0:
        testcases.append({ 'in_args': tcdata[:-1], 'out': tcdata[-1] })
        tcdata[:] = []

for tidx, tcase in enumerate(testcases):
    print(f'# Testcase {tidx+1}')
    print(f'[input]')
    print('  ' + ', '.join(tcase['in_args']))

    args = (json.loads(e) for e in tcase['in_args'])

    result = solution.solution(*args)

    print('[    Your answer] {}'.format(json.dumps(result)))
    print('[Expected answer] {}'.format(json.dumps(json.loads(tcase['out']))))
