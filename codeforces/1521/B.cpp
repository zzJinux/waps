#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int N;
		int a[100000];
		scanf("%d",&N);
		for(int i=0; i<N; ++i) {
			scanf("%d",a+i);
		}
		printf("%d\n", N-1);
		int minidx = 0;
		int minval = a[0];
		for(int i=1; i<N; ++i) {
			if(minval > a[i]) {
				minidx = i;
				minval = a[i];
			}
		}
		for(int i=(minidx+1)%2; i<N; i+=2) {
			printf("%d %d %d %d\n", minidx+1, i+1, minval, minval+1);
		}
		for(int i=minidx%2; i<N; i+=2) {
			if(i == minidx) continue;
			printf("%d %d %d %d\n", minidx+1, i+1, minval, minval);
		}
	}
	return 0;
}
