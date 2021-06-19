#include <cstdio>
#include <cctype>
using namespace std;
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		char _s[51];
		char *s = _s;
		bool vis[26]={};
		scanf("%*d %s", s);
		char pr=0;
		for(; isupper(*s); ++s) {
			if(pr != *s) {
				if(vis[*s-'A']) {
					puts("NO");
					pr=0;
					break;
				} else {
					vis[*s-'A']=true;
				}
			}
			pr=*s;
		}
		if(pr) {
			puts("YES");
		}
		
	}
	return 0;
}
