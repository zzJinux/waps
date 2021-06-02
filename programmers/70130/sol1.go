func solution(a []int) int {
	N := len(a)
	indss := make([][]int, N)
	for i, v := range a {
		indss[v] = append(indss[v], i)
	}

	ans:=0
	for _, inds := range indss {
		fans:=0
		from:=0
		for _, ind := range inds {
			if ind-from > 0 {
				fans++
				from=ind+1
			} else if ind+1<N && a[ind+1]!=a[ind] {
				fans++
				from=ind+2
			} else {
				from=ind+1
			}
		}
		if ans < fans {
			ans = fans
		}
	}
	return ans*2
}
