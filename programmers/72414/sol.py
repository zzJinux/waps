def conv_ts(s):
    a=s.split(':')
    return int(a[0])*3600+int(a[1])*60+int(a[2])
def conv_tsr(s):
    x, y=s.split('-')
    return conv_ts(x), conv_ts(y)
def inv_conv_ts(x):
    return f'{x//3600:02d}:{x%3600//60:02d}:{x%60:02d}'
    
def solution(_play_time, _adv_time, _logs):
    play_time = conv_ts(_play_time)
    adv_time = conv_ts(_adv_time)
    logs = list(map(lambda e: conv_tsr(e), _logs))
    
    points=[]
    for log in logs:
        b, e = log
        points.append((b, 0))
        points.append((e, 1))
    points.append((0, 0))
    points.append((0, 1))
    points.sort(key=lambda elem: elem[0])
    
    
    ppp=[]
    incrate=0
    i=0
    while i<len(points):
        t = points[i][0]
        while i<len(points) and points[i][0] == t:
            if points[i][1] == 0:
                incrate+=1
            else:
                incrate-=1
            i+=1
        ppp.append((t, incrate))
        
    cfa, cfb = 0, 0
    xa = 0
    ia = 0
    xb = 0
    ib = 0
    for i in range(len(ppp)-1):
        t, incrate = ppp[i]
        nt = ppp[i+1][0]
        if adv_time < nt:
            cfb += (adv_time-t)*incrate
            xb = adv_time
            ib = i
            break
        else:
            cfb += (nt-t)*incrate
    else:
        xb = adv_time
        ib = len(ppp) - 1
    
    ans = 0
    ansval = cfb
    while ib < len(ppp)-1:
        inc_a = ppp[ia][1]
        inc_b = ppp[ib][1]
        
        next_xa = ppp[ia+1][0]
        next_xb = ppp[ib+1][0]
        
        d_xa = next_xa - xa
        d_xb = next_xb - xb
        
        dd = min(d_xa, d_xb)
        
        cfa += dd * inc_a
        cfb += dd * inc_b
        xa += dd
        xb += dd
        
        if d_xa > d_xb:
            ib += 1
        elif d_xa < d_xb:
            ia += 1
        else:
            ia += 1
            ib += 1
        
        if ansval < cfb - cfa:
            ans = xa
            ansval = cfb - cfa
            
        
    return inv_conv_ts(ans)
