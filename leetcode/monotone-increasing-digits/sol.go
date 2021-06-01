import "strconv"
var solution = monotoneIncreasingDigits
func monotoneIncreasingDigits(N int) int {
	digits := strconv.Itoa(N)
	lll := 0
	for _ = range digits {
		lll = 10*lll + 1;
	}
	ret := 0
	for _, digit := range digits {
		loo := lll - lll/10
		d := int(digit) - '0'
		dloo := d * loo
		if d * lll > N && 0 < d {
			ret += dloo - 1
			break
		} else {
			ret += dloo
		}
		N -= dloo
		lll /= 10
	}
	return ret
}
