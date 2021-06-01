func solution(n int, lost []int, reserve []int) int {
    a := make([]int, n+1)
    for i:=1; i<=n; i++ {
        a[i]=1
    }
    for _, val := range lost {
        a[val]--
    }
    for _, val := range reserve {
        a[val]++
    }
    ans := 0
    for i:=1; i<=n; i++ {
        if a[i] == 0 {
            if a[i-1] > 1 {
                a[i-1]--
                a[i]++
            }
            if i<n && a[i+1] > 1 {
                a[i+1]--
                a[i]++
            }
        }
        if a[i] > 0 {
            ans++
        }
    }
    return ans
}
