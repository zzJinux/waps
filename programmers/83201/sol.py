def solution(scores):
    N = len(scores)
    answer = ''
    for i in range(N):
        mn, mx, mnc, mxc = 100, 0, 0, 0
        summ=0
        for j in range(N):
            s = scores[j][i]
            if mn>s:
                mn, mnc = s, 1
            elif mn==s:
                mnc+=1
            if mx<s:
                mx, mxc = s, 1
            elif mx==s:
                mxc+=1
            summ += s

        mys=scores[i][i]
        cnt=N
        if (mys==mn and mnc==1) or (mys==mx and mxc==1):
            summ -= mys
            cnt=N-1

        avg = summ/cnt
        print(avg)

        ch='F'
        if avg>=90:
            ch='A'
        elif avg>=80:
            ch='B'
        elif avg>=70:
            ch='C'
        elif avg>=50:
            ch='D'
            
        answer += ch

    return answer
