#include <cstdio>
using namespace std;

void run_case() {
	int n, m;
	scanf("%d%d%*d%*d",&n,&m);
	printf("%d %d %d %d\n", 1, 1, n, m);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
