#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

// 코너(500)와 직선도로(100)
// cost[HOR][i][j] : (i,j) 종점, 마지막 직선도로가 가로방향
// cost[VER][i][j] : (i,j) 종점, 마지막 직선도로가 세로방향

#define HOR 0
#define VER 1
/* row */int const DX[]={1, 0, -1, 0};
/* col */int const DY[]={0, 1, 0, -1};
// DOWN, RIGHT, UP, LEFT

int const DCOST[2][4] = {
    /* hor */{500, 0, 500, 0},
    /* ver */{0, 500, 0, 500}
};

using VI=vector<int>;
using VII=vector<VI>;
struct E { int x, y, fdir; };

int solution(VII board) {
    int N = board.size();
    VII cost[2]={VII(N, VI(N)), VII(N, VI(N))};
    queue<E> q;
    for(int a=0; a<2; ++a) for(int i=0;i<N;++i) for(int j=0;j<N;++j){
        cost[a][i][j]=0x7fFFffFF;
    }
    q.push({0, 0, HOR});
    q.push({0, 0, VER});
    cost[0][0][0]=cost[1][0][0]=0;
    while(!q.empty()) {
        E e=q.front(); q.pop();
        
        for(int d=0;d<4;++d) {
            int nx = e.x + DX[d], ny = e.y + DY[d];
            if(nx<0||nx>=N||ny<0||ny>=N||board[nx][ny]==1) continue;
            
            int dcost = DCOST[e.fdir][d];
            int nfdir = 1-d%2;
            
            int val = cost[e.fdir][e.x][e.y] + dcost + 100;
            auto&rrr=cost[nfdir][nx][ny];
            if(rrr>val) {
                rrr=val;
                q.push({nx, ny, nfdir});
            }
        }
    }
    return min(cost[HOR][N-1][N-1], cost[VER][N-1][N-1]);
}
