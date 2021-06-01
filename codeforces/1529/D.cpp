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

int const MOD = 998244353;
int N;
int D[1000001];
void run_case() {
	scanf("%d", &N);
	for(int i=1; i<=N; ++i) {
		for(int j=1; j*i<=N; ++j) {
			++D[i*j];
		}
	}
	if(N==1) puts("1");
	else if(N==2) puts("3");
	else {
		int a=1, b=3, F;
		for(int i=3; i<=N; ++i) {
			// F = (3*b - a + D[i] - 2*D[i-1])
			F = (MOD+ 3LL*b%MOD -a +(MOD+ D[i] - 2*D[i-1])%MOD)%MOD;
			a=b; b=F;
		}
		printf("%d", F);
	}
}

int main() {
	int tc;
	run_case();
	return 0;
}
