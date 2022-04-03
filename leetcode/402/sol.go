var solution = removeKdigits
func removeKdigits(s string, K int) string {
    N := len(s)
    ans := make([]byte, 0, N-K)
    a := make([]byte, 0, N)
    for i:=0; i<K; i++ {
        var j int
        for j=len(a)-1; j>=0 && a[j] > s[i]; j-- {}
        a = a[:j+2]
        a[j+1] = s[i]
    }
    for i:=K; i<N; i++ {
        var j int
        for j=len(a)-1; j>=0 && a[j] > s[i]; j-- {}
        a = a[:j+2]
        a[j+1] = s[i]
        ans = ans[:len(ans)+1]
        ans[len(ans)-1] = a[0]
        a = a[1:]
    }
    var z int
    for ; z < len(ans) && ans[z] == '0'; z++ {}
    if len(ans) == z {
        return "0"
    }
    return string(ans[z:])
}
