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

void run_case() {
	int N, a[100];
	scanf("%d",&N);
	for(int i=0;i<N;++i) {
		scanf("%d",a+i);
	}
	if(N==1) {
		puts("0");
		return;
	}
	sort(a, a+N);
	int j;
	for(j=1; j<N; ++j) {
		if(a[j-1] != a[j]) break;
	}
	printf("%d\n", N-j);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
