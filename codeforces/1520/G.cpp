#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N,M,W;
int brd[2000][2000];
long long dist[2000][2000];
int tx[]={1, 0, -1, 0}, ty[]={0, -1, 0, 1};

int main() {
	scanf("%d%d%d",&N,&M,&W);
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			scanf("%d",&brd[i][j]);
		}
	}

	auto bfs = [&](int sx, int sy) {
		long long portd = -1;
		queue<pair<int,int>> q;
		dist[sx][sy] = 0;
		q.push({sx,sy});
		while(!q.empty()) {
			auto e = q.front();q.pop();
			int x=e.first, y=e.second;
			auto d=dist[x][y];
			if(brd[x][y]>0) {
				if(portd==-1 || portd > d + brd[x][y]) {
					portd = d + brd[x][y];
				}
			}
			
			for(int i=0; i<4; ++i) {
				int nx=x+tx[i], ny=y+ty[i];
				auto nd=d+W;
				if(nx<0||nx>=N||ny<0||ny>=M||brd[nx][ny]==-1) continue;
				if(dist[nx][ny]==-1 || dist[nx][ny] > nd) {
					dist[nx][ny] = nd;
					q.push({nx, ny});
				}
			}
		}

		return portd;
	};

	for(int i=0; i<N; ++i) memset(dist[i], 0xFF, M*sizeof(long long));
	auto s2port = bfs(0, 0);
	auto ans = dist[N-1][M-1];

	for(int i=0; i<N; ++i) memset(dist[i], 0xFF, M*sizeof(long long));
	auto t2port = bfs(N-1, M-1);

	if(s2port != -1 && t2port != -1 && (ans==-1 || ans > s2port+t2port)) ans = s2port+t2port;

	printf("%lld\n", ans);
	return 0;
}
