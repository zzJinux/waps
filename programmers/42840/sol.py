def m(answers, pat):
    def g():
        while True: yield from pat
    return sum(e[0]==e[1] for e in zip(answers, g()))
def solution(answers):
    aa = [ m(answers, pat) for pat in [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5,]]]
    mx = max(aa)
    return [ i+1 for i,v in enumerate(aa) if v==mx ]
