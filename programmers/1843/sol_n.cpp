#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr) {
    size_t N = arr.size();
    int allsum=stoi(arr[0]);
    vector<int> hv(1, 0), sv(1, stoi(arr[0]));
    for(int i=1; i<N; i+=2) {
        bool isminus = arr[i][0] == '-';
        int val = stoi(arr[i+1]);
        allsum += val;
        if(isminus) {
            hv.push_back(val);
            sv.push_back(0);
            
        }
        else {
            *(sv.end()-1) += val;
        }
    }
    int M = hv.size();
    int com=0, mcom=0x7fFFffFF;
    for(int i=1; i<M; ++i) {
        com += hv[i]+sv[i];
        if(mcom>com) mcom=com;
        com -= sv[i];
    }
    if(M==1) mcom = 0;
    return allsum - 2*mcom;
}
