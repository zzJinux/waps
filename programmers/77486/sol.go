func solution(enroll []string, referral []string, seller []string, amount []int) []int {
	N:=len(enroll)
	names := make(map[string]int)
	par := make([]int, N)
	tt := make([]int, N)

	names["-"] = -1
	for i, v := range enroll {
		names[v]=i
	}

	for i, v := range referral {
		par[i] = names[v]
	}

	for j, v := range seller {
		i := names[v]
		for s:=amount[j]*100; s>0 && i!=-1; i, s = par[i], s/10 {
			tt[i] += s - s/10
		}
	}

    return tt
}
