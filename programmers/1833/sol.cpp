#include <vector>
#include <algorithm>
using namespace std;

int dedup(int N, int arr[]) {
    int shi=0;
    for(int i=1; i<N; ++i) {
        if(arr[i-1] == arr[i]) ++shi;
        else if(shi > 0) arr[i-shi] = arr[i];
    }
    return N-shi;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int N = data.size();
    int cxa[5000], cya[5000];
    
    int l_cxa=0, l_cya=0;
    for(vector<int> &p:data) {
        int x=p[0], y=p[1];
        cxa[l_cxa++]=x;
        cya[l_cya++]=y;
    }
    sort(cxa, cxa+l_cxa);
    sort(cya, cya+l_cya);
    l_cxa = dedup(l_cxa, cxa);
    l_cya = dedup(l_cya, cya);
    
    vector<vector<int>> dd(l_cxa+1, vector<int>(l_cya+1, 0));
    for(vector<int> &p:data) {
        p[0] = lower_bound(cxa, cxa+l_cxa, p[0]) - cxa;
        p[1] = lower_bound(cya, cya+l_cya, p[1]) - cya;
        dd[p[0]+1][p[1]+1] = 1;
    }
    
    for(int i=1; i<=l_cxa; ++i) {
        for(int j=1; j<=l_cya; ++j) {
            dd[i][j] += dd[i][j-1] + dd[i-1][j] - dd[i-1][j-1];
        }
    }
    
    int answer = 0;
    for(int ii=0; ii<N-1; ++ii) {
        for(int jz=ii+1; jz<N; ++jz) {
            int x1 = data[ii][0]+1, y1 = data[ii][1]+1;
            int x2 = data[jz][0]+1, y2 = data[jz][1]+1;
            if(x1==x2 || y1==y2) continue;
            if(x1>x2) {
                int t=x1;x1=x2;x2=t;
            }
            if(y1>y2) {
                int t=y1;y1=y2;y2=t;
            }
            
            int cnt = dd[x2-1][y2-1]-dd[x2-1][y1]-dd[x1][y2-1]+dd[x1][y1];
            if(cnt==0) {
                ++answer;
            }
        }
    }
    return answer;
}
