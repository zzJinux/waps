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

int L, R;
void run_case() {
	long long ans = 0;
	scanf("%d%d",&L,&R);
	for(long long a=10; ; a*=10) {
		int b=a/10;
		ans += (R/a - L/a)*10 + (R/b%10 - L/b%10);
		if(R/a == 0) break;
	}
	printf("%lld\n", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
