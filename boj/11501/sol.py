import sys
T = int(input())
for _ in range(T):
    N = int(input())
    arr = [ int(tok) for tok in input().split() ]
    mxi = [0]*N
    mxi[N-1] = N-1
    for i in reversed(range(N-1)):
        if arr[i] > arr[mxi[i+1]]:
            mxi[i] = i
        else:
            mxi[i] = mxi[i+1]
    ans = 0
    for i in range(N-1):
        if mxi[i] != i:
            ans += arr[mxi[i]] - arr[i]
    print(ans)
