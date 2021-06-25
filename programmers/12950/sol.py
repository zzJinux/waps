def solution(a1,a2):
    return [[x+y for x,y in zip(r1,r2)] for r1,r2 in zip(a1,a2)]
