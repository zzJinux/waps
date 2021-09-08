def solution(wei, h2h):
    def c1(i):
        n,d=0,0
        ndtbl={'N':(0,0),'W':(1,1),'L':(0,1)}
        for ch in h2h[i]:
            n,d=n+ndtbl[ch][0],d+ndtbl[ch][1]
        return n/d if d>0 else 0
    def c2(i):
        return sum(int(ch=='W' and wei[i]<wei[j]) for j, ch in enumerate(h2h[i]))
    return list(map(lambda e: e[3]+1, sorted((-c1(i), -c2(i), -wei[i], i) for i in range(len(wei)))))
