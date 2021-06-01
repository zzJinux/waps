#include <string>
#include <vector>
#include <cstring>

using namespace std;
vector<string> solution(vector<string> vs) {
    vector<string> answer;
    
    for(auto &s:vs) {
        int const N=s.size();
        int M=0;
        int patcnt=0;
        for(int i=0; i<N; ++i) {
            char ch=s[i];
            if(ch=='0' && M>=2 && s[M-2]=='1' && s[M-1]=='1') {
                M-=2;
                ++patcnt;
            } else s[M++] = ch;
        }
        if(patcnt==0) {
            answer.push_back(s);
            continue;
        }
        
        s[M]=s[M+1]=s[M+2]='1';
        int ipos = s.find("111");
        
        for(int i=M-1; i>=ipos; --i) {
            s[i+patcnt*3]=s[i];
        }
        for(int i=ipos, n=patcnt; n--; i+=3) {
             memcpy(s.data()+i, "110", 3);
        }
        
        answer.push_back(s);
    }
    
    return answer;
}
