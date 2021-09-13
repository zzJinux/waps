#include <iostream>
using namespace std;
int N;
char nodes[1000][101];
int SRC, DEST, dd[1000], vis[1000];

int get_dist(int a, int b) {
	int sum=0;
	for(int i=0;nodes[a][i];++i) {
		int z=nodes[a][i]-nodes[b][i];
		sum += z*z;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;++i) {
		cin>>nodes[i];
		dd[i]=0x7fFFffFF;
	}
	cin>>SRC>>DEST;
	--SRC, --DEST;

	dd[SRC]=0;
	int Rem=N;
	while(true) {
		int u=-1, mn=0x7fFFffFF;
		for(int cnt=0, i=0; cnt<Rem; ++i) {
			if(vis[i]) continue;
			++cnt;
			if(mn > dd[i]) {
				u = i;
				mn = dd[i];
			}
		}
		if(u==DEST) break;
		
		vis[u] = true;
		--Rem;
		for(int i=0, cnt=0; cnt<Rem; ++i) {
			if(vis[i]) continue;
			++cnt;
			int val = dd[u] + get_dist(u, i);
			if(dd[i] > val) dd[i] = val;
		}
	}
	cout<<dd[DEST];
	return 0;
}
