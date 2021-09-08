#include <iostream>
#include <sstream>
#include <string>
using namespace std;

constexpr int MAXR=20, MAXC=20;
int R, C;
int hori[MAXR+1][MAXC+1];
int vert[MAXR+1][MAXC+1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string line;
	while(true) {
		getline(cin, line);
		istringstream(line) >> R >> C;
		if(R==0) break;
		for(int i=0;i<=R;++i) for(int j=0;j<=C;++j) hori[i][j]=vert[i][j]=0;
		for(int i=0; i<=2*R; ++i) {
			getline(cin, line);
			if(i&1) {
				int r = (i+1)/2;
				for(int j=0; j<=C; ++j) {
					if(line[j]=='|') {
						vert[r][j] = vert[r-1][j]+1;
					}
				}
			}
			else {
				int r = i/2;
				for(int j=1; j<=C; ++j) {
					if(line[j-1]=='-') {
						hori[r][j] = hori[r][j-1]+1;
					}
				}
			}
		}

		int ans = 0;
		for(int r=1; r<=R; ++r) {
			for(int c=1; c<=C; ++c) {
				int _1=hori[r][c], _2=vert[r][c];
				int mn = _1<_2?_1:_2;

				for(int d=1; d<=mn; ++d) {
					if(hori[r-d][c] >= d && vert[r][c-d] >= d) ++ans;
				}
			}
		}
		cout << ans << " squares\n";
	}
	return 0;
}
