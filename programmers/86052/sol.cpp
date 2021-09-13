#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool traces[4][500][500];
int dy[]={0, 1, 0, -1, 0};
int *dx=dy+1;
vector<int> solution(vector<string> grid) {
	int M = grid.size();
	int N = grid[0].size();

    vector<int> answer;
	for(int i=0; i<M; ++i) {
		for(int j=0; j<N; ++j) {
			for(int di=0; di<4; ++di) {
				if(traces[di][i][j]) continue;

				int len = 0;
				int x=i, y=j, d=di;
				while(true) {
					if(traces[d][x][y]) break;
					traces[d][x][y] = true;
					++len;

					x=(M+x+dx[d])%M, y=(N+y+dy[d])%N;
					char ch = grid[x][y];
					switch(ch) {
					case 'L':
						d=(d+1)%4;
						break;
					case 'R':
						d=(d+3)%4;
						break;
					default:
						break;
					}
				}

				answer.push_back(len);
			}
		}
	}
	sort(answer.begin(), answer.end());
    return answer;
}
