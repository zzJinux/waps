#include <cstdio>
#include <algorithm>
using namespace std;

using LL = long long;
int N;
pair<LL,LL> tt[100000];
int main() {
	scanf("%d",&N);
	for(int i=0; i<N; ++i) {
		scanf("%lld%lld",&tt[i].second,&tt[i].first);
	}
	sort(tt, tt+N);
	for(int i=N-1; i>0; --i) {
		tt[i].first -= tt[i-1].first;
	}

	LL ans=0;
	int revi=N-1;
	int j=0;
	for(int i=0; i<N; ++i) {
		LL b=tt[i].first;

		while(j<i && b>0) {
			LL aone = tt[j].second;
			LL nb = max(0LL, b-aone);
			LL cnt = b-nb;

			ans += cnt;
			b -= cnt;
			tt[j].second -= cnt;
			if(tt[j].second == 0) {
				++j;
			}
		}

		while(revi>=i && b>0) {
			LL aone = tt[revi].second;
			LL nb = max(0LL, b-aone);
			LL cnt = b-nb;
			
			ans += cnt*2;
			b -= cnt;
			tt[revi].second -= cnt;
			if(tt[revi].second == 0) {
				--revi;
			}
		}

		if(b>0) break;
	}

	for(int i=0; i<N; ++i) {
		ans += tt[i].second;
	}

	printf("%lld",ans);
	return 0;
}
