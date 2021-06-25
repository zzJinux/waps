def solution(n,money):
    dp=[0]*(n+1)
    dp[0]=1
    for c in money:
        for i in range(c,n+1):
            dp[i]+=dp[i-c]
            dp[i]%=1000000007
    return dp[n]
