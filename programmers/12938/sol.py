def solution(n, s):
    v=s//n
    return [-1] if s<n else [v]*(n-s%n) + [v+1]*(s%n)
