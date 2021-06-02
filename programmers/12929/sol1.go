func solution(n int) int {
	a:=make([]int, n+1)
	a[0]=1
	for i:=1; i<=n; i++ {
		s:=0
		for k:=0; k<i; k++ {
			s+=a[k]*a[i-1-k]
		}
		a[i]=s
	}
	return a[n]
}
