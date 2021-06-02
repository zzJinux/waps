func solution(n int) int64 {
	if n==1 { return 1 }
	a,b:=1,2
	for n-=2; n>0; n-- { a,b=b,(a+b)%1234567 }
	return int64(b)
}
