var N, ans int
var colchk [12]bool
var diachk, riachk [23]bool
func search(r int) {
	if r == N {
		ans++
		return
	}
	for j:=0; j<N; j++ {
		z,x,c := &colchk[j], &diachk[N-1+r-j], &riachk[r+j]
		if !*z && !*x && !*c {
			*z,*x,*c=true,true,true
			search(r+1)
			*z,*x,*c=false,false,false
		}
	}
}
func solution(_N int) int {
	N = _N
	search(0)
    return ans
}
