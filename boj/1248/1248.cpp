#include <cstdio>
#include <cstring>
constexpr int N_MAX=10;
int N;
char mm[N_MAX][N_MAX];
int arr[N_MAX], up[N_MAX];
int main() {
	scanf("%d ", &N);
	for(int i=0;i<N;++i) {
		for(int j=i;j<N;++j) {
			char ch;
			scanf("%c ",&ch);
			char &r=mm[i][j];
			if(ch=='-') --r;
			else if(ch=='+') ++r;
		}
	}
	int C=0;
	while(C<N && !mm[C][C]) {
		++C;
		printf("0 ");
	}


	int i=C;
	while(i<N) {
		++arr[C];
		i=C+1;
		while(i<N && i>C) {
			if(up[i]>0) {
				if(++arr[i] == up[i]) {
					up[i]=0;
					--i;
				}
				else ++i;
			}
			else {
				if(!mm[i][i]) { up[i]=1; arr[i]=0; ++i; continue; }
				int ssum=0;
				int vlo=0;
				up[i]=11;
				for(int J=i-1; J>=0; --J) {
					ssum+=mm[J][J]*arr[J];
					if(mm[J][i-1]*mm[i][i]>=0) continue;
					int K = ssum*mm[J][i-1];
					int sgn=mm[i][i]*mm[J][i];
					if(sgn<0) {
						if(up[i]>K) up[i]=K;
					}
					else if(sgn>0) {
						if(vlo<K) vlo=K;
					}
					else {
						if(up[i]>K+1) up[i]=K+1;
						if(vlo<K-1) vlo=K-1;
					}
				}
				arr[i] = vlo+1;
				if(arr[i] >= up[i]) {
					up[i]=0;
					--i;
					if(vlo>0) {
						up[i]=0;
						--i;
					}
				}
				else ++i;
			}
		}
	}
	for(int i=C;i<N;++i) printf("%d ", mm[i][i]*arr[i]);
	return 0;
}
