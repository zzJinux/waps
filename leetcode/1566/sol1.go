var solution=containsPattern
func containsPattern(arr []int, M int, K int) bool {
	N:=len(arr)
	for p:=0; p<M && p+M<=N; p++ {
		cnt:=1
		i:=p
		for j:=p+M; j+M<=N; j+=M {
			if cnt==K {
				break
			}

			var z int
			for z=0; z<M; z++ {
				if arr[i+z] != arr[j+z] {
					break
				}
			}
			if z<M {
				i = j
				cnt=0
			}
			cnt++
		}
		if cnt==K {
			return true
		}
	}
	return false
}
