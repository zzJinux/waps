var solution=containsPattern
func containsPattern(arr []int, M int, K int) bool {
	N:=len(arr)
	emax:=0
	e:=0
	for i:=0; i+M<N; i++ {
		if arr[i]==arr[i+M] {
			e++
			if emax<e { emax=e }
		} else {
			e=0
		}
	}
	return emax/M>=K-1
}

