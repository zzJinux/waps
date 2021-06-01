INFO_DICT = {
    'cpp': 0,
    'java': 1,
    'python': 2,
    
    'backend': 0,
    'frontend': 1,
    
    'junior': 0,
    'senior': 1,
    
    'chicken': 0,
    'pizza': 1,
    
    '-': -1
}

def parse_info(info):
    tokens = info.split(' ')
    return tuple(map(lambda e: INFO_DICT[e], tokens[:-1])), int(tokens[-1])

def parse_query(query):
    tokens = query.split(' and ')
    tokens[-1:] = tokens[-1].split(' ')
    return tuple(map(lambda e: INFO_DICT[e], tokens[:-1])), int(tokens[-1])

def solution(info, query):
    infostore = [
        [
            [
                [
                    [] for _ in range(2)
                ] for _ in range(2)
            ] for _ in range(2)
        ] for _ in range(3)
    ]
    
    for e in info:
        inds, score = parse_info(e)
        infostore[inds[0]][inds[1]][inds[2]][inds[3]].append(score)
    for a in range(3):
        for b in range(2):
            for c in range(2):
                for d in range(2):
                    infostore[a][b][c][d].sort()
    
    answer = []
    for q in query:
        inds, _score = parse_query(q)
        score = int(_score)
        
        def gen_views():
            for a in [inds[0]] if inds[0] != -1 else range(3):
                for b in [inds[1]] if inds[1] != -1 else range(2):
                    for c in [inds[2]] if inds[2] != -1 else range(2):
                        for d in [inds[3]] if inds[3] != -1 else range(2):
                            yield infostore[a][b][c][d]
                            
        cnt = 0
        for view in gen_views():
            lo, hi = 0, len(view)
            while lo<hi:
                mi=(lo+hi)//2
                if view[mi] >= score:
                    hi = mi
                else:
                    lo = mi+1
            cnt += len(view) - lo
        answer.append(cnt)
        
    return answer
