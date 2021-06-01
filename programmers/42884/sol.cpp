#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // cam_loc may move to the the left (never to the right)
    //         *
    // [...............]
    //       %
    //   [...]
    
    //         *
    // [...............]
    //       [...]
    
    //         *
    // [...............]
    //               *
    //           [...]
    sort(routes.begin(), routes.end(), [](auto&lhs, auto&rhs) {
        return lhs[0]<rhs[0];
    });
    int lastloc=-30001;
    int ans=0;
    for(auto&route:routes) {
        int b=route[0], e=route[1];
        if(lastloc > e) lastloc=e;
        else if(lastloc < b) {
            ++ans;
            lastloc=e;
        }
    }
    return ans;
}
