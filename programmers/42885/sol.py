def solution(a, limit):
    a.sort()
    i,j=0,len(a)-1
    answer=0
    while i<=j:
        answer+=1
        while i<j and a[i]+a[j]>limit:
            answer+=1
            j-=1
        i+=1
        j-=1
    return answer
