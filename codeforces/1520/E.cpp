#include <cstdio>
using namespace std;
long long solve(int N, char const *s) {
	if(N==1) return 0;
	int i;
	int M=0;
	for(int i=0; i<N; ++i) {
		if(s[i]=='*') ++M;
	}
	int c=0;
	for(i=0;; ++i) {
		if(s[i]=='*') ++c;
		if(c==(M+1)/2) break;
	}
	int lb=i, rb=i+1;
	if(N%2) {
		lb=i-1, rb=i+1;
	}
 
	long long ans=0;
	int j;
	for(i=lb, j=lb; i>=0; --i) {
		while(j>=0 && s[j]!='*') --j;
		if(j<0) break;
		ans+=i-j;
		--j;
	}
	for(i=rb, j=rb; i<N; ++i) {
		while(j<N && s[j]!='*') ++j;
		if(j>=N) break;
		ans+=j-i;
		++j;
	}
	return ans;
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int N;
		char s[1000001];
		scanf("%d %s", &N, s);
		printf("%lld\n", solve(N, s));
	}
	return 0;
}
