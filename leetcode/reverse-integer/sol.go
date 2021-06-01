var solution = reverse
func b2i(b bool) (i int32) {
	i=0; if b { i=1 }; return
}
func sgn(x int32) int32 {
	return b2i(0<x) - b2i(x<0)
}
func reverse(_x int) int {
	var x, A, PM, NM int32 = int32(_x), 0, 0x7fFFffFF, -0x80000000
	for ; x/10!=0; x/=10 {
		A = 10*A+x%10
	}
	if A>0 && (x%10-PM%10) > 10*sgn(PM/10-A) { return 0; }
	if A<0 && (x%10-NM%10) < 10*sgn(NM/10-A) { return 0; }
	return int(10*A+x%10)
}
