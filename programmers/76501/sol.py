def solution(a, s):
    return sum(b*(t*2-1) for b,t in zip(a,s))
