#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned popcount(unsigned v) {
    unsigned c;
    for(c=0;v;++c) v&=v-1;
    return c;
}

unsigned a2b(string const &a) {
    unsigned b=0;
    for(char ch:a) {
        b |= 1u<<(26-(ch-'A'));
    }
    return b;
}

string b2a(unsigned b) {
    string s;
    s.reserve(popcount(b));
    for(int i=0;i<26;++i) {
        if(1u<<(26-i) & b) s.push_back('A'+i);
    }
    return s;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    int N = orders.size();
    vector<unsigned> vb(N);
    for(int i=0;i<N; ++i) {
        vb[i]=a2b(orders[i]);
    }
    unsigned ss = 0;
    for(int i=0;i<N-1;++i) {
        for(int j=i+1;j<N;++j) {
            ss |= vb[i]&vb[j];
        }
    }
    
    pair<int, vector<unsigned>> uans[11];
    for(int e:course) uans[e].first = 1;
    
    for(unsigned s=ss;s;s=(s-1)&ss) {
        int z = popcount(s);
        if(z > 10) continue;
        
        auto &u = uans[z];
        if(u.first == 0) continue;
        
        int cnt=0;
        for(unsigned b:vb) {
            if(s == (b&s)) ++cnt;
        }
        if(cnt<2) continue;
        
        if(cnt==u.first) {
            u.second.push_back(s);
        } else if(cnt>u.first) {
            u.first = cnt;
            u.second.clear();
            u.second.push_back(s);
        }
    }
    
    vector<unsigned> ans;
    for(int c:course) {
        ans.insert(ans.end(), uans[c].second.begin(), uans[c].second.end());
    }
    
    vector<string> answer(ans.size());
    for(int i=0; i<ans.size(); ++i) {
        answer[i] = b2a(ans[i]);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
