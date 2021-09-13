#include <vector>
using namespace std;

using LL=long long;
LL solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	int N = g.size();
	LL lo=0, up=0;
	for(int i=0; i<N; ++i) {
		LL mx = 1LL*((g[i]+s[i]+w[i]-1)/w[i])*2*t[i] - t[i];
		if(up<mx) {
			up=mx;
		}
	}

	LL ans=up--;
	while(lo<=up) {
		LL T=(lo+up)/2;
		LL all_g = 0, all_s = 0, ela = 0;
		for(int i=0; i<N; ++i) {
			LL cap, sh_g, sh_s;

			cap = T>=t[i] ? ( 1 +(T-t[i])/(2*t[i]) ) * w[i] : 0;

			sh_g = cap < g[i] ? cap : g[i];
			sh_s = cap - sh_g < s[i] ? cap - sh_g : s[i];
			all_g += sh_g;
			all_s += sh_s;

			ela += sh_g < s[i] - sh_s ? sh_g : s[i] - sh_s;
		}

		if(ela > all_g - a) {
			ela = all_g - a;
		}
		if(all_g < a || all_s + ela < b) {
			lo = T+1;
		}
		else {
			ans=T;
			up = T-1;
		}
	}
	return ans;
}
