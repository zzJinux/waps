#include <vector>
#include <unordered_map>

using namespace std;

using LL=long long;

struct UnF {
    unordered_map<LL, LL> par;
    unordered_map<LL, int> rank;
    
    bool exists(LL x) {
        return par.find(x) != par.end();
    }
    
    void acti(LL x) {
        par[x] = x;
        rank[x] = 1;
    }
    
    void op_union(LL x, LL y) {
        x = find(x);
        y = find(y);
        int rx = rank[x], ry = rank[y];
        if(rx < ry) {
            par[x] = y;
            rank[y] = rx + ry;
        } else {
            par[y] = x;
            rank[x] = rx + ry;
        }
    }
    
    LL find(LL x) {
        LL root=x;
        for(;;) {
            LL pr=par[root];
            if(pr==root) break;
            root=pr;
        }
        for(;;) {
            LL pr=par[x];
            if(pr==root) break;
            par[x]=root;
            x=pr;
        }
        return root;
    }
};

vector<long long> solution(long long k, vector<long long> room_number) {
    UnF unf;
    unordered_map<LL, LL> nextempty;
    vector<LL> answer;
    answer.reserve(room_number.size());
    
    vector<LL> upt;
    for(LL e:room_number) {
        upt.clear();
        while(unf.exists(e)) {
            upt.push_back(e);
            e = nextempty[unf.find(e)];
        }
            
        unf.acti(e);
        answer.push_back(e);
        
        for(LL u:upt) {
            unf.op_union(u, e);
        }
        
        LL ee = unf.find(e);
        nextempty[ee]=e+1;
    }
    
    return answer;
}
