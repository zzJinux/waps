def solution(dr):
    i=0
    aa=[[0,1]]
    po={'S':1,'D':2,'T':3}
    while i<len(dr):
        if dr[i] == '*':
            aa[-2][1]*=2
            aa[-1][1]*=2
            i+=1
        elif dr[i] == '#':
            aa[-1][1]*=-1
            i+=1
        else:
            v=int(dr[i])
            if dr[i+1]=='0':
                v=10
                i+=1
            aa.append([v**po[dr[i+1]],1])
            i+=2
    return sum(e[0]*e[1] for e in aa)
