def gcd(a,b):
    while b:
        a,b=b,a%b
    return a
def lcm(a,b):
    g=gcd(a,b)
    return a//g*b
def solution(arr):
    v=arr[0]
    for i in range(1,len(arr)):
        v=lcm(v,arr[i])
    return v
