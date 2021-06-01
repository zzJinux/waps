#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int A, B;
		scanf("%d %d", &A, &B);
		if(B==1) {
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%lld %lld %lld\n", 1LL*A*(B+1), 1LL*A*(B-1), 2LL*A*B);
	}
	return 0;
}
