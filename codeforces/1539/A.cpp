#include <cstdio>
using namespace std;

int N,X,T;
void run_case() {
	scanf("%d%d%d",&N,&X,&T);
	long long p = (T)/X;
	long long ans = 1LL*(N-1)*N/2;
	if(p<N)
		ans = (p-1)*p/2 + p*(N-p);
	printf("%lld\n", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
