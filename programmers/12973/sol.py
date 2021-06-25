def solution(s):
    t=[]
    for c in s:
        if len(t)>0 and t[-1]==c:
            t.pop()
        else:
            t.append(c)
    return int(len(t)==0)
