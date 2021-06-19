#include <cstdio>
#include <vector>
using namespace std;
 
using VI=vector<int>;
using VII=vector<VI>;
bool sol(VII &ans) {
	int N = ans.size();
	if(N==1) {
		ans[0][0]=1;
		return true;
	} else if(N==2) {
		return false;
	} else if(N==3) {
		ans={
			{2, 9, 7},
			{4, 6, 3},
			{1, 8, 5}
		};
		return true;
	}
 
	// N>=4
	int z=1;
	for(int e=0; e<2; ++e) {
		for(int f=0; f<2; ++f) {
			for(int i=0; i<N-1; i+=2) {
				for(int j=0; j<N-1; j+=2) {
					ans[i+e][j+f]=z++;
				}
			}
		}
	}
	if(N%2) {
		int zz=z;
		for(int c=0; c<N-1; ++c) {
			ans[N-1][c]=z++;
			ans[c][N-1]=z++;
		}
		ans[N-1][0]=z;
		ans[N-1][N-1]=zz;
	}
	return true;
}
 
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int N;
		scanf("%d", &N);
		VII ans(N, VI(N));
		if(sol(ans)) {
			for(int i=0; i<N; ++i) {
				for(int j=0; j<N; ++j) {
					printf("%d ", ans[i][j]);
				}
				putchar('\n');
			}
		} else {
			puts("-1");
		}
		
	}
	return 0;
}
