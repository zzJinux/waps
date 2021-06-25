#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int M, K, arr[100001], rows[2][449];
bool check(int n, function<void(int *)> cb = nullptr) {
	memset(rows[0], 0, n*sizeof(int));
	auto r1 = rows[0], r2 = rows[1];

	int cur=1, used=0;
	for(int i_=0; i_<n; ++i_) {

		cb(r2+1);
		swap(r1, r2);
	}
	return true;
}
void run_case() {
	scanf("%d%d",&M,&K);
	for(int i=1;i<=K;++i) scanf("%d",arr+i);

	int lo, ri, mi;
	for(lo=1; lo*lo-(lo/2)*(lo/2)<M; ++lo);
	for(ri=1; (ri+1)/2*ri<M; ++ri);
	int ans=ri--;

	while(lo<ri) {
		int mi=(lo+ri)/2;
		if(check(mi)) {
			ans=mi; ri=mi-1;
		}
		else {
			lo=mi+1;
		}
	}

	printf("%d\n",ans);
	check(ans, [ans](int *row) {
		for(int i=0; i<ans; ++i) {
			printf("%d ", row[i]);
		}
		puts("");
	});
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
