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

int gcd(int a, int b) {
	while(b) {
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
void run_case() {
	int K;
	scanf("%d", &K);
	int g = gcd(K, 100-K);
	printf("%d\n", 100/g);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
}
