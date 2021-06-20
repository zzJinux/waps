#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long K,X;
long long arr[200000];
vector<long long> kk;
int main() {
	scanf("%d%lld%lld",&N,&K,&X);
	for(int i=0; i<N; ++i) {
		scanf("%lld", arr+i);
	}
	sort(arr,arr+N);
	for(int i=1; i<N; ++i) {
		auto g=arr[i]-arr[i-1];
		if(g>X) {
			auto k=(g+(X-1))/X - 1;
			kk.push_back(k);
		}
	}
	int ans = kk.size()+1;
	sort(kk.begin(), kk.end());
	for(int i=0; i<kk.size() && K-kk[i]>=0; ++i) {
		K-=kk[i];
		--ans;
	}
	printf("%d\n", ans);
	return 0;
}
