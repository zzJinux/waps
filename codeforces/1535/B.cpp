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
int arr[2000];
int gcd(int a, int b) {
	while(b) {
		int t=b;b=a%b;a=t;
	}
	return a;
}
void run_case() {
	int ans=0;
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%d", arr+i);
	for(int i=0;i<N-1;++i) {
		for(int j=i+1;j<N;++j) {
			int a=arr[i], b=arr[j];
			if(a%2 && b%2) {
				if(gcd(a,b)>1) ans++;
			}
			else ans++;
		}
	}
	printf("%d\n",ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
