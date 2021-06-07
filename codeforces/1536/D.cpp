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
 
int N,arr[200000];
void run_case() {
	scanf("%d",&N);
	for(int i=0;i<N;++i) scanf("%d", arr+i);
 
	set<int> s;
	auto p = s.insert(arr[0]);
	auto cur = p.first;
	for(int i=0;i<N;++i) {
		int v=arr[i];
		int cv=*cur;
		if(v == cv) continue;
		if(v > cv) {
			auto next=cur;
			++next;
			if(next != s.end() && *next<v) {
				puts("NO");
				return;
			}
		}
		else {
			auto prev=cur;
			if(cur != s.begin() && *--prev>v) {
				puts("NO");
				return;
			}
		}
		p = s.insert(v);
		cur = p.first;
	}
	puts("YES");
}
 
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		run_case();
	}
	return 0;
}
