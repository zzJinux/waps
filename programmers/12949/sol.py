def solution(m1, m2):
    return [ [ sum(r1[k]*m2[k][j] for k in range(len(r1))) for j in range(len(m2[0])) ] for r1 in m1 ]
