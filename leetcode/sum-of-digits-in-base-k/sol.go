var solution = sumBase
func sumBase(n int, k int) int {
	ans:=0
	for ; n>0; n/=k {
		ans += n%k
	}
	return ans
}
