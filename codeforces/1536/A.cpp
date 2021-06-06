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
int gcd(int a, int b) {
	int t;
	while(b) {t=b;b=a%b;a=t;}
	return a;
}
bool chk[101];
void run_case() {
	scanf("%d",&N);
	int g=0, mx, q=false;
	int zero=0;
	for(int i=0;i<N;++i) {
		int a;
		scanf("%d",&a);
		if(a<0) {
			q=true;
			continue;
		}
		g=gcd(g,a);
		if(mx<a) mx=a;
		if(a==0) zero=1;
	}
	if(q) {
		puts("NO");
		return;
	}

	puts("YES");
	printf("%d\n", mx/g+zero);
	for(int i=g*(1-zero);i<=mx;i+=g) {
		printf("%d ", i);
	}
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
