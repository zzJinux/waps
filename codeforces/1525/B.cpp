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

void run_case() {
	int N;
	int a[50];
	scanf("%d", &N);
	for(int i=0; i<N; ++i) scanf("%d", a+i);
	bool f=false;
	for(int i=1;i<N;++i) {
		if(a[i-1] > a[i]) f=true;
	}
	if(!f) {
		puts("0");
		return;
	}

	if(1==a[0] || N==a[N-1]) {
		puts("1");
		return;
	}
	if(1==a[N-1] && N==a[0]) {
		puts("3");
		return;
	}

	puts("2");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
