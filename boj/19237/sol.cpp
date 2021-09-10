#include <iostream>
using namespace std;
int N, M, K;
int shid[20][20];
int shts[20][20];
bool nshid[20][20];
int shx[401], shy[401], shd[401];
int pr[401][5][4];

int dx[]={0, -1, 1, 0, 0};
int dy[]={0, 0, 0, -1, 1};

int fnext(int T, int id) {
	int x, y, d;
	x=shx[id]; y=shy[id]; d=shd[id];

	for(int i=0; i<4; ++i) {
		int gx, gy, gd;
		gd = pr[id][d][i];
		gx = x + dx[gd];
		gy = y + dy[gd];

		if(gx>=0&&gx<N&&gy>=0&&gy<N && (shid[gx][gy]==0 || T-shts[gx][gy]>=K)) {
			return gd;
		}
	}
	for(int i=0; i<4; ++i) {
		int gx, gy, gd;
		gd = pr[id][d][i];
		gx = x + dx[gd];
		gy = y + dy[gd];

		if(gx>=0&&gx<N&&gy>=0&&gy<N && (shid[gx][gy]==id && T-shts[gx][gy]<K)) {
			return gd;
		}
	}
	return *((int volatile*)nullptr); // impossible
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M>>K;
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			int id;cin>>id;
			if(id!=0) {
				shid[i][j]=id;
				shx[id]=i;
				shy[id]=j;
			}
		}
	} 

	for(int id=1; id<=M; ++id) {
		int d;cin>>d;
		shd[id]=d;
	}

	for(int id=1; id<=M; ++id) {
		for(int rd=1; rd<=4; ++rd) {
			for(int i=0; i<4; ++i) {
				int d;cin>>d;
				pr[id][rd][i]=d;
			}
		}
	}

	int T, xx=1;
	for(T=0;T<1000 && xx<M;++T) {
		for(int id=1; id<=M; ++id) {
			if(shd[id]==0) continue;
			int x, y;
			x=shx[id]; y=shy[id];
			
			int nx, ny, nd;
			nd = fnext(T, id);
			nx = x + dx[nd];
			ny = y + dy[nd];

			if(nshid[nx][ny]) {
				shd[id] = 0;
				++xx;
				continue;
			}
			nshid[nx][ny] = true;

			shx[id]=nx;
			shy[id]=ny;
			shd[id]=nd;
		}

		for(int id=1; id<=M; ++id) {
			if(shd[id]==0) continue;
			int x, y;
			x=shx[id]; y=shy[id];

			nshid[x][y] = false;
			shid[x][y] = id;
			shts[x][y] = T+1;

		}
	}
	printf("%d\n", xx<M ? -1 : T);
	return 0;
}
