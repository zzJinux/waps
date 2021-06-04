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

int K,Q;
char S[1u<<18];
int aa[1u<<19];
void run_case() {
	scanf("%d%s%d",&K,S+1,&Q);
	unsigned Z=1u<<K;
	for(int i=Z; i<(Z<<1); ++i) {
		aa[i]=1;
	}
	for(int i=Z-1; i>0; --i) {
		char ch = S[Z-i];
		switch(ch) {
		case '0':
			aa[i]=aa[i*2+1];
			break;
		case '1':
			aa[i]=aa[i*2];
			break;
		default :
			aa[i]=aa[i*2]+aa[i*2+1];
			break;
		}
	}
	while(Q--) {
		int q;
		char c;
		scanf("%d %c ",&q,&c);
		S[q]=c;
		for(int i=Z-q; i>0; i>>=1) {
			char ch = S[Z-i];
			switch(ch) {
			case '0':
				aa[i]=aa[i*2+1];
				break;
			case '1':
				aa[i]=aa[i*2];
				break;
			default :
				aa[i]=aa[i*2]+aa[i*2+1];
				break;
			}
		}
		printf("%d\n", aa[1]);
	}
	
}

int main() {
	int tc=1;
	while(tc--) {
		run_case();
	}
	return 0;
}
