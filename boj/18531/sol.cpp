#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char rows[3][5001];
vector<int> f12[5000];

inline char at(char *s, int i) {
	return s[i%N];
}
vector<int> f(char *base, char *other) {
	vector<int> r;
	for(int b=0; b<N; ++b) {
		int i;
		for(i=0; i<N; ++i) {
			if(base[i] == at(other,b+i)) break;
		}
		if(i==N) r.push_back(b);
	}
	return r;
}

void printvec(vector<int> &v) {
	for(int e:v) {
		printf("%d ", e);
	}
	puts("");
}
int main() {
	scanf("%s%s%s",rows[0],rows[1],rows[2]);
	N=strlen(rows[0]);

	auto v01 = f(rows[0], rows[1]);
	auto v02 = f(rows[0], rows[2]);
	auto v12 = f(rows[1], rows[2]);

	for(int i01:v01) {
		for(int i02:v02) {
			f12[(N+i02-i01)%N].push_back(i01);
		}
	}

	int ans=0x7fFFffFF;
	for(int i12:v12) {
		if(f12[i12].size() == 0) continue;
		for(int i01:f12[i12]) {
			int p1 = i01, p2 = (i12+i01)%N, d01, d02, d12;
			d01 = min(p1, N-p1);
			d02 = min(p2, N-p2);
			d12 = abs(p1-p2);
			d12 = min(d12, N-d12);

			int a = d01+d02+d12 - max({d01,d02,d12});
			if(ans > a) ans = a;
		}
	}

	printf("%d\n", ans==0x7fFFffFF?-1:ans);
	return 0;
}
