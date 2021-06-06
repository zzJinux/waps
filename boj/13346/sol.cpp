#include <cstdio>
#include <algorithm>
int Q,N,D;
char f1[101], f2[101];
int64_t dp[2][201];
auto pdp=dp[0], cdp=dp[1];
int main() {
	scanf("%d%d%d%s%s",&Q,&N,&D,f1,f2);
	pdp[0]=1;
	for(int i=0; i<N; ++i) {
		if(f1[i]==f2[i]) {
			std::copy(pdp, pdp+D+1, cdp);
			for(int a=2; a<=D; ++a) {
				cdp[a]+=pdp[a-2]*(Q-1);
			}
		}
		else {
			cdp[0]=0;
			for(int a=1; a<=D; ++a) {
				cdp[a]=pdp[a-1]*2;
			}
			for(int a=2; a<=D; ++a) {
				cdp[a]+=pdp[a-2]*(Q-2);
			}
		}
		std::swap(cdp, pdp);
	}
	printf("%lld\n", pdp[D]);
	return 0;
}
