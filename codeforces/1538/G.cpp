#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

long long x,y,a,b;
int ans;
bool chk(int s, int t) {
	return a*s + b*t - x <= 0 && b*s + a*t - y <= 0;
}
void run_case() {
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	long long sdel = b*x - a*y, tdel = a*x - b*y;
	auto s = min(b*x, a*y);
	auto t = min(a*x, b*y);
	ans = int(max(s,t)/(a*b));

	if((sdel<0 && tdel>0) || (sdel>0 && tdel<0)) {
		int is, it;
		long long d = a*a - b*b;
		if(d<0) {
			tdel=-tdel;
			sdel=-sdel;
			d=-d;
		}
		is = tdel/d;
		it = (-sdel)/d;
		int t = int(is+it);
		if(chk(is+1, it) || chk(is, it+1)) {
			++t;
		}
		if(ans < t) ans = t;
	}
	printf("%d\n", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
