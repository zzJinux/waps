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

int N, arr[200000];
void run_case() {
	scanf("%d",&N);
	int sum=0;
	for(int i=0;i<N;++i) scanf("%d",arr+i);
	for(int i=0;i<N;++i) {
		sum+=arr[i];
	}
	if(sum%N) {
		puts("-1");
		return;
	}
	int avg=sum/N;
	int ans=0;
	for(int i=0; i<N; ++i) {
		if(arr[i]>avg) ++ans;
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
