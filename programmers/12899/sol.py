def solution(n):
    dd=[]
    while n>0:
        dd.append((n-1)%3)
        n=(n-1)//3
    return ''.join(str(2**i) for i in reversed(dd))
