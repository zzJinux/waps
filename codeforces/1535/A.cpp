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
	int a[4];
	for(int i=0; i<4;++i) {
		scanf("%d", a+i);
	}
	int b1=a[0]>a[1]?a[0]:a[1];
	int b2=a[2]>a[3]?a[2]:a[3];
	if(b1>b2) swap(b1, b2);
	sort(a,a+4);
	puts(b1==a[2]&&b2==a[3]?"YES":"NO");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
