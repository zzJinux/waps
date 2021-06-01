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

int N;
int arr[100000], d[100000];
int mx;
void run_case() {
	scanf("%d", &N);
	for(int i=0; i<N; ++i) {
		scanf("%d", arr+i);
	}
	sort(arr, arr+N);

	int zu = upper_bound(arr, arr+N, 0) - arr;
	int ans = zu;
	int mnd=0x7fFFffFF, d;
	for(int i=1; i<zu; ++i) {
		d = arr[i]-arr[i-1];
		if(mnd > d) mnd = d;
	}
	if(zu < N && arr[zu] <= mnd) ++ans;
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
