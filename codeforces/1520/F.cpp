#include <cstdio>
#include <cstdlib>
using namespace std;

int N, K;
int bit[200001];
int cache[200001];

void update(int x, int v) {
	for(;x<=N;x+=x&-x) {
		bit[x]+=v;
	}
}
int query(int x) {
	int v=0;
	for(;x>0;x-=x&-x) {
		v+=bit[x];
	}
	return v;
}

void run_case() {
	scanf("%d",&K);
	int l=1, r=N, m, x;
	while(l<r) {
		m=(l+r)/2;
		if(cache[m]!=-1) {
			x = cache[m] + query(m);
		}
		else {
			printf("? %d %d\n", 1, m); fflush(stdout);
			scanf("%d", &x);
			if(x==-1) {
				exit(0);
			}
			cache[m] = x - query(m);
		}

		if(m-(x)<K) l=m+1;
		else r=m;
	}
	printf("! %d\n", l);
	fflush(stdout);
	update(l, 1);
	return;
}
int main() {
	int tc;
	scanf("%d%d",&N,&tc);
	for(int i=1;i<=N;++i) cache[i]=-1;
	while(tc--) {
		run_case();
	}
	return 0;
}
