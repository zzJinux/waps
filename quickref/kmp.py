import sys
def pre_kmp(x):
    m = len(x)
    knj = [-1]*(m+1)
    kmp_next = [-1]*(m+1)
    i = 0
    j = -1
    while i<m:
        while j>-1 and x[i] != x[j]:
            j = kmp_next[j]
        i+=1
        j+=1
        # kmp_next[i] = j
        kmp_next[i] = j if i==m or x[i] != x[j] else kmp_next[j]
        knj[i] = j
    return knj, kmp_next

def show(x):
    knj, kmp_next = pre_kmp(x)
    for ch in x:
        sys.stdout.write(f'{ch:>3}')
    sys.stdout.write("  $\n")
    for z in knj:
        sys.stdout.write(f'{z:>3}')
    sys.stdout.write("\n")
    for z in kmp_next:
        sys.stdout.write(f'{z:>3}')
    sys.stdout.write("\n")

show('abABCabAEabABCabA')
show('GCAGAGAG')
show('aaaa')
