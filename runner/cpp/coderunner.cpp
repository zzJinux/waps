#include <string>
#include <vector>
#include <queue>

using namespace std;

int popcount(unsigned x) {
	int c = 0;
	for (;x!=0;x>>=1)
		if(x&1)
			c++;
	return c;
}

int solution(vector<int> info, vector<vector<int>> edges) {
	int N = info.size();

	unsigned bit_sheep=0, bit_wolf=0;
	for(int i=0; i<N; ++i) {
		if(info[i]) {
			// wolf
			bit_wolf |= 1u<<i;
		}
		else {
			// sheep
			bit_sheep |= 1u<<i;
		}
	}

	vector<int> sheepcnt(1u<<N);
	vector<bool> possible(1u<<N);
	for(unsigned sst=0; sst<(1u<<N); ++sst) {
		int n_sheep = popcount(sst & bit_sheep);
		int n_wolf = popcount(sst & bit_wolf);

		sheepcnt[sst] = n_sheep;
		possible[sst] = n_sheep > n_wolf;
	}

	vector<vector<int>> chld(N, vector<int>());
	for(auto &edge : edges) {
		int u=edge[0], v=edge[1];
		chld[u].push_back(v);
	}

	vector<bool> reachable(1u<<N);
	reachable[1] = true;

	queue<unsigned> qq;
	qq.push(1);
	while(!qq.empty()) {
		auto sst = qq.front();qq.pop();

		for(int bi=0; bi<N; ++bi) {
			// skip the unvisited
			if( !(sst & (1u<<bi)) ) continue;

			auto try_push = [&](int u) -> void {
				if(sst & (1u<<u)) return;

				auto nsst = sst | (1u<<u);

				if(!possible[nsst]) return;
				if(reachable[nsst]) return;

				reachable[nsst] = true;
				qq.push(nsst);
			};

			for(int v : chld[bi]) {
				try_push(v);
			}
		}
	}

	int ans = 0;
	for(unsigned sst=0; sst<(1u<<N); ++sst) {
		if(!reachable[sst]) continue;

		if(ans < sheepcnt[sst]) {
			ans = sheepcnt[sst];
		}
	}

	return ans;
}
#include <iostream>
#include <string>
using namespace std;

template<typename T>
ostream& operator<<(ostream &os, vector<T> const &valvec) {
    size_t N = valvec.size();
    if(N==0) {
        os << "[]";
        return os;
    }

    os << "[";
    os << valvec[0];
    for(size_t i=1; i<N; ++i) {
        os << ", " << valvec[i];
    }
    os << "]";
    return os;
}

template<>
ostream& operator<<(ostream &os, vector<bool> const &valvec) {
    size_t N = valvec.size();
    if(N==0) {
        os << "[]";
        return os;
    }

    os << "[";
    os << (valvec[0] ? "true" : "false");
    for(size_t i=1; i<N; ++i) {
        os << ", " << (valvec[i] ? "true" : "false");
    }
    os << "]";
    return os;
}

template<>
ostream& operator<<(ostream &os, vector<string> const &valvec) {
    size_t N = valvec.size();
    if(N==0) {
        os << "[]";
        return os;
    }

    os << "[";
    os << "\"" << valvec[0] << "\"";
    for(size_t i=1; i<N; ++i) {
        os << ", " << "\"" << valvec[i] << "\"";
    }
    os << "]";
    return os;
}
#include<functional>
int main() {
	// std::decltype(std::function{solution})::result_type ans;

	auto ans = solution({0,0,1,1,1,0,1,0,1,0,1,1}, {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}});
	cout << ans << "\n";

	ans = solution({0,1,0,1,1,0,1,0,0,1,0}, {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10}});
	cout << ans << "\n";
	return 0;
}

