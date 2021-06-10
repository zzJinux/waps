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

int N, L, R, arr[200000];
void run_case() {
	scanf("%d%d%d",&N,&L,&R);
	for(int i=0; i<N; ++i) scanf("%d", arr+i);
	sort(arr, arr+N);
	long long ans=0;
	for(int i=0; i<N-1; ++i) {
		ans += upper_bound(arr+i+1, arr+N, R-arr[i]) - lower_bound(arr+i+1, arr+N, L-arr[i]);
	}
	printf("%lld\n",ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
