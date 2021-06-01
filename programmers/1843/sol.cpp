#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int nums[101];
bool ops[100]; // minus if true
int dmn[101][101];
int dmx[101][101];

int dfs(int si, int ei, bool mx) {
    if(mx) {
        int &rrr = dmx[si][ei];
        if(rrr==0x80000000) {
            for(int mi=si; mi<ei; ++mi) {
                int lhs=dfs(si, mi, true) , rhs=dfs(mi+1, ei, ops[mi]==false);
                int t;
                if(ops[mi]) t=lhs-rhs;
                else t=lhs+rhs;
                if(rrr < t) rrr = t;
            }
        }
        return rrr;
    }
    else {
        int &rrr = dmn[si][ei];
        if(rrr==0x7fFFffFF) {
            for(int mi=si; mi<ei; ++mi) {
                int lhs=dfs(si, mi, false) , rhs=dfs(mi+1, ei, ops[mi]==true);
                int t;
                if(ops[mi]) t=lhs-rhs;
                else t=lhs+rhs;
                if(rrr > t) rrr = t;
            }
        }
        return rrr;
    }
}

int solution(vector<string> arr) {
    int N = arr.size()/2;
    for(int i=0; i<=N; ++i) {
        nums[i] = strtoul(arr[i*2].c_str(), nullptr, 10);
        for(int j=0; j<=N; ++j) {
            dmn[i][j] = 0x7fFFffFF;
            dmx[i][j] = 0x80000000;
        }
        dmn[i][i] = nums[i];
        dmx[i][i] = nums[i];
    }
    for(int i=0; i<N; ++i) {
        ops[i] = arr[i*2+1][0] == '-';
    }
    return dfs(0, N, true);
}
