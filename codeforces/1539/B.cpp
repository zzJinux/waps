#include <cstdio>
using namespace std;

int N,Q;
char song[100001];
int pp[26][100001];
int main() {
	scanf("%d%d%s",&N,&Q,song);

	for(int i=0; i<N; ++i) {
		for(int j=0; j<26; ++j) {
			pp[j][i+1] = pp[j][i];
		}
		int ord = song[i]-'a';
		pp[ord][i+1]++;
	}

	for(int q_=0; q_<Q; ++q_) {
		int l,r;
		scanf("%d%d",&l,&r);
		int sum = 0;

		for(int j=0; j<26; ++j) {
			sum += (j+1)*(pp[j][r] - pp[j][l-1]);
		}
		printf("%d\n", sum);
	}
	return 0;
}
