#include <stdio.h>
int N, arr[501], dd[501][501];
int main() {
	scanf("%d%d%d",&N,arr,arr+1);
	for(int i=2;i<=N;++i) scanf("%*d%d",arr+i);
	for(int z=2;z<=N;++z) {
		for(int i=0; i+z<=N; ++i) {
			int vmn=0x7fFFffFF;
			for(int j=i+1;j<i+z;++j) {
				int v = arr[i]*arr[j]*arr[i+z] + dd[i][j]+dd[j][i+z];
				if(vmn>v) vmn=v;
			}
			dd[i][i+z]=vmn;
		}
	}
	printf("%d",dd[0][N]);
	return 0;
}
