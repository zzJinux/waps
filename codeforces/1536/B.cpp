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

int N;
char ss[1001];
void run_case() {
	scanf("%d%s",&N,ss);
	bool single[26]={};
	for(int i=0;i<N;++i) {
		single[ss[i]-'a']=true;
	}
	for(int i=0;i<26;++i) {
		if(!single[i]) {
			putchar(i+'a');putchar('\n');
			return;
		}
	}
	bool db[26][26]={};
	for(int i=0;i<N-1;++i) {
		db[ss[i]-'a'][ss[i+1]-'a']=true;
	}
	for(int i=0;i<26;++i) {
		for(int j=0;j<26;++j) {
			if(!db[i][j]) {
				putchar(i+'a');putchar(j+'a');putchar('\n');
				return;
			}
		}
	}
	bool tri[26][26][26]={};
	for(int i=0;i<N-2;++i) {
		tri[ss[i]-'a'][ss[i+1]-'a'][ss[i+2]-'a']=true;
	}
	for(int i=0;i<26;++i) {
		for(int j=0;j<26;++j) {
			for(int k=0;k<26;++k) {
				if(!tri[i][j][k]) {
					putchar(i+'a');putchar(j+'a');putchar(k+'a');putchar('\n');
					return;
				}
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
