def solution(m,n,puds):
    pudchk = set(tuple(e) for e in puds)
    r1,r2=[0]*(m+1),[0]*(m+1)
    r2[1]=1
    for ri in range(1, n+1):
        for ci in range(1, m+1):
            r1[ci] = 0
            if (ci,ri) not in pudchk:
                r1[ci] = (r1[ci-1]+r2[ci])%1000000007
        r1,r2=r2,r1
    return r2[m]
