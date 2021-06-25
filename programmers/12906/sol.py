import itertools
def solution(arr):
    return [k for k,_ in itertools.groupby(arr)]
