import sys
# line = input().strip()
# nums = [int(e) for e in line.split()]

def gen(nums):
    N = len(nums)
    print(N)
    readable=False
    fout = sys.stdout
    for i in range(N):
        if readable:
            for _ in range(i):
                fout.write(' ')
        s=0
        for j in range(i, N):
            s += nums[j]
            if s>0: fout.write('+')
            elif s<0: fout.write('-')
            else: fout.write('0')
        if readable:
            fout.write('\n')


