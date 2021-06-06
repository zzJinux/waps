#include <iostream>
#include <cstdint>
using namespace std;
int const MOD=1000'000'007;
int N,Q[500001];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>N;
	int64_t W=0, v;
	for(int i=0; i<N; ++i) {
		int a;
		cin>>a;
		int &q=Q[a];
		v=(MOD+W-q)%MOD;
		q=(q+v+1)%MOD;
		W=(W+v+1)%MOD;
	}
	printf("%lld\n", W);
	return 0;
}
