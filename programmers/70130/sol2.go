func solution(a []int) int {
	N:=len(a)
	froms:=make([]int, N)
	anss:=make([]int, N)
	for i,v:=range a {
		if i-froms[v]>0 {
			anss[v]++
			froms[v]=i+1
		} else if i+1<N && a[i]!=a[i+1] {
			anss[v]++
			froms[v]=i+2
		} else {
			froms[v]=i+1
		}
	}

	ans:=0
	for _, v:=range anss {
		if(ans<v) {ans=v}
	}
    return ans*2
}
