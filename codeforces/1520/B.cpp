#include <cstdio>
using namespace std;
 
int sol(int N) {
	int d=0, x=0;
	for(int n=N; n; n/=10) {
		x=10*x+1;
		++d;
	}
	return (d-1)*9 + N/x;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int N;
		scanf("%d", &N);
		printf("%d\n", sol(N));
	}
	return 0;
}
