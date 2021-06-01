#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int M = rocks.size();
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    int le = rocks[n], ri=distance;
    // A naive attempt to set the lower bound
    for(int i=n+1; i<M+1; ++i) {
        if(le > rocks[i]-rocks[i-1]) le = rocks[i]-rocks[i-1];
    }
    while(le<ri) {
        int mi=(le+ri+1)/2;
        int prev = 0; int rmcnt=0;
        int i;
        for(i=0; i<M && rmcnt<n; ++i) {
            if(rocks[i]-prev < mi) {
                ++rmcnt;
            } else {
                prev = rocks[i];
            }
        }
        for(; i<=M; ++i) {
            if(rocks[i]-prev < mi) break;
            prev = rocks[i];
        }
        if(i<=M) {
            ri = mi-1;
        } else {
            le = mi;
        }
    }
    return le;
}
