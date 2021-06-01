#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> ans(N);
    int *st = new int[N], h_st=0;
    st[h_st++] = 0;
    for(int i=1; i<N; ++i) {
        int j;
        while(h_st && prices[j = st[h_st-1]]>prices[i]) {
            ans[j] = i-j;
            --h_st;
        }
        st[h_st++] = i;
    }
    for(int i=0; i<h_st; ++i) {
        ans[st[i]] = N-1-st[i];
    }
    
    delete[] st;
    return ans;
}
