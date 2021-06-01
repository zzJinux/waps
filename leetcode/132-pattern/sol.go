var solution = find132pattern
type E struct { a, b int }
func find132pattern(nums []int) bool {
	N := len(nums)
	st := make([]E, 1, N)
	st[0] = E{ 0x7fFFffFF, 0x7fFFffFF }
	ilow := nums[0]
	for k:=1; k<N; k++ {
		v := nums[k]
		h := len(st)
		for ; h>0; h-- {
			if v <= st[h-1].a {
				if ilow < v {
					st = st[0:h+1]
					st[h] = E{ ilow, v }
				}
				break
			} else if v < st[h-1].b {
				return true
			}
		}
		if ilow > v {
			ilow = v
		}
	}
	return false
}
