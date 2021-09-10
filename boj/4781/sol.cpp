#include <iostream>
#include <algorithm>
using namespace std;
struct E{int c, p;};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, _M1, _M2, dp[10001];E ee[5000];char _;
	while(true) {
		cin>>N>>_M1>>_>>_M2;
		if(N==0) break;
		M=_M1*100+_M2;
		for(int i=1;i<=M;++i) dp[i]=0;

		for(int i=0;i<N;++i) {
			int _p1, _p2;
			cin>>ee[i].c>>_p1>>_>>_p2;
			ee[i].p=_p1*100+_p2;
		}
		sort(ee, ee+N, [](E &a, E &b) {
			return a.p<b.p||(a.p==b.p && a.c>b.c);
		});
		unique(ee, ee+N, [](E &a, E &b) {
			return a.p==b.p;
		});
		int ans=0;
		for(int w=1;w<=M;++w) {
			for(int i=0;i<N;++i) {
				if(w<ee[i].p) break;
				if(dp[w] < dp[w-ee[i].p]+ee[i].c) {
					dp[w] = dp[w-ee[i].p]+ee[i].c;
				}
			}
			if(ans<dp[w]) {
				ans=dp[w];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
