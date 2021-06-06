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
char ww[500001];
map<pair<int,int>, int> cont;
int gcd(int a, int b) {
	int t;while(b) t=b,b=a%b,a=t;return a;
}
void run_case() {
	cont.clear();
	scanf("%d%s",&N,ww);
	int nd=0, nk=0;
	for(int i=0;i<N;++i) {
		nd+=(ww[i]=='D');
		nk+=(ww[i]=='K');
		int g=gcd(nd,nk);
		pair<int, int> v{nd/g,nk/g};
		int nv = cont[v]+1;
		cont[v]=nv;
		printf("%d ", nv);
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
