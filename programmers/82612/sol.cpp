long long solution(int p, int m, int c) {
	long long ans = 1LL*p*c*(c+1)/2 - m;
	return ans<0?0:ans;
}
