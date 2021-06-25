def solution(n):
    ans=0
    while n>0:
        ans = ans*3 + n%3
        n//=3
    return ans
