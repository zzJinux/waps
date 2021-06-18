#include <cstdio>
using namespace std;

void run_case() {
	int n;
	scanf("%d",&n);
	int s=0;
	for(int i=0;i<n;++i) {
		int a;
		scanf("%d",&a);
		s+=a;
	}
	if(s>=n) {
		printf("%d\n", s-n);
	}
	else {
		puts("1");
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
