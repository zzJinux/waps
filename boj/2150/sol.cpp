#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N, M;
vector<vector<int>> alist;
vector<bool> sccvis;
vector<vector<int>> scclist;
vector<int> low;
vector<int> stk;
int stk_h;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>N>>M;

	alist.resize(N+1);
	sccvis.resize(N+1);
	low.resize(N+1);
	stk.resize(N+1);
	for(int i=0;i<M;++i) {
		int a, b;
		cin>>a>>b;
		alist[a].push_back(b);
	}

	int idcnt = 1;
	function<void(int)> tarj = [&](int u) {
		int uid = idcnt;
		int bottom = stk_h;

		low[u] = idcnt;
		stk[stk_h] = u;
		++idcnt; ++stk_h;

		for(int v:alist[u]) {
			if(!low[v]) {
				tarj(v);
				low[u] = min(low[u], low[v]);
			}
			else if(!sccvis[v]) {
				low[u] = min(low[u], low[v]);
			}
		}

		if(low[u]!=uid) return;

		vector<int> scc;
		int Z = stk_h - bottom;
		scc.resize(Z);
		for(int i=0; i<Z; i++) {
			int v = stk[i+bottom];
			sccvis[v] = true;
			scc[i] = v;
		}
		stk_h = bottom;

		sort(scc.begin(), scc.end());
		scclist.push_back(move(scc));
	};

	for(int i=1; i<=N; ++i) {
		if(low[i] == 0) tarj(i);
	}

	sort(scclist.begin(), scclist.end());

	cout << scclist.size() << '\n';
	for(auto &scc:scclist) {
		for(int v:scc) {
			cout << v << ' ';
		}
		cout << -1 << '\n';
	}

	return 0;
}
