#include <cstdio>
#include <algorithm>
using namespace std;

void run_case() {
	int n; scanf("%d",&n);
	int arr[200000];
	for(int i=0; i<n; ++i) {
		scanf("%d", arr+i);
	}
	sort(arr, arr+n);

	int mni = 1;
	for(int i=2; i<n; ++i) {
		int d=arr[i] - arr[i-1];
		if(arr[mni] - arr[mni-1] > d) {
			mni = i;
		}
	}
	printf("%d ", arr[mni-1]);
	for(int i=mni+1; i<n; ++i) {
		printf("%d ", arr[i]);
	}
	for(int i=0; i<mni-1; ++i) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[mni]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
