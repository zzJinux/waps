#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
 
using VI=vector<int>;
long long sol(VI const &arr) {
	int N = arr.size();
	unordered_map<int, int> cc;
	for(int i=0; i<N; ++i) {
		int d=arr[i]-i;
		if(cc.find(d) == cc.end()) {
			cc.insert({d, 1});
		} else {
			++cc[d];
		}
	}
	long long ans=0;
	for(auto e:cc) {
		long long k = e.second;
		ans += (k-1)*k/2;
	}
	return ans;
}
 
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int N;
		scanf("%d", &N);
		VI arr(N);
		for(int i=0; i<N; ++i) {
			int a;scanf("%d", &a);
			arr[i]=a;
		}
		printf("%lld\n", sol(arr));
	}
	return 0;
}
