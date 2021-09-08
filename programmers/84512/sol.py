MAXL = 5
def solution(word):
    ordmap = {'A':1, 'E':2, 'I':3, 'O':4, 'U':5}
    syms = [ordmap[ch] for ch in word]
    for _ in range(MAXL-len(word)):
        syms.append(0)

    x=1
    cnt=0
    for i in reversed(range(MAXL)):
        if syms[i] > 0:
            cnt += (syms[i]-1)*x + 1
        x=1+MAXL*x
    return cnt
