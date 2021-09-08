#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VP = vector<pair<int, int>>;
int _dy[] = {0, 1, 0, -1, 0};
int *_dx = _dy+1;

void normalize(VP &points) {
	sort(points.begin(), points.end());
	int tx = points[0].first, ty = points[0].second;
	for(pair<int, int> &p : points) {
		p.first -= tx;
		p.second -= ty;
	}
}

vector<VP> getpieces(VVI const &board) {
	int M = board.size(), N = board[0].size();
	VVB vis(M, VB(N));

	vector<VP> pieces;
	for(int i=0; i<M; ++i) {
		for(int j=0; j<N; ++j) {
			if(vis[i][j] || board[i][j]==0) continue;
			VP piece;

			function<void(int, int)> dfs = [&](int x, int y) {
				piece.emplace_back(x, y);

				for(int _di=0; _di<4; ++_di) {
					int nx=x+_dx[_di], ny=y+_dy[_di];
					if(nx<0 || nx>=M || ny<0 || ny>=N || vis[nx][ny] || board[nx][ny]==0) continue;

					vis[nx][ny] = true;
					dfs(nx, ny);
				}
			};

			vis[i][j] = true;
			dfs(i, j);

			pieces.push_back(piece);
		}
	}

	return pieces;
}

int solution(VVI game_board, VVI table) {
	for(auto &row : game_board) {
		for(int j=0; j<row.size(); ++j) row[j] = !row[j];
	}

	auto ppp1 =  getpieces(game_board);
	auto ppp2 =  getpieces(table);

	for(auto &piece : ppp1) {
		normalize(piece);
	}

	VB used(ppp2.size());
	int ans = 0;
	for(auto &refpiece : ppp1) {

		bool iden = false;
		int sz = refpiece.size();

		for(int a2=0; a2<ppp2.size(); ++a2) {
			if(used[a2]) {
				continue;
			}

			// piece-piece comparison

			auto &testpiece = ppp2[a2];
			if(sz != testpiece.size()) {
				continue;
			}

			for(int roti=0; roti<4; ++roti) {
				normalize(testpiece);

				int q;
				for(q=0; q<sz && refpiece[q] == testpiece[q]; ++q) {;}
				if(q==sz) {
					// identical piece!
					iden = true;
					used[a2] = true;
					break;
				}

				for(auto &p : testpiece) {
					int xx = p.first, yy = p.second;
					p.first = -yy;
					p.second = xx;
				}
			}

			if(iden) {
				break;
			}
		}
		if(iden) {
			ans += sz;
		}
	}

    return ans;
}
