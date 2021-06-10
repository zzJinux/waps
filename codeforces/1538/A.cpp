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

int N, arr[100];
void run_case() {
	scanf("%d",&N);
	for(int i=0; i<N; ++i) scanf("%d", arr+i);
	int mn=0, mx=0;
	for(int i=1; i<N; ++i) {
		if(arr[mn]>arr[i]) {
			mn = i;
		}
		else if(arr[mx]<arr[i]) {
			mx = i;
		}
	}
	if(mn > mx) {
		swap(mn, mx);
	}
	printf("%d\n", min({mn+1+(N-mx), mx+1, N-mn}));
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
