#include <queue>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;
using PII=pair<int, int>;
int solution(vector<int> stones, int k) {
    int N=stones.size();
    auto compare = [](PII const &lhs, PII const &rhs) {
        return lhs.first < rhs.first;
    };
    
    vector<PII> ee;
    for(int i=0; i<N; ++i) {
        ee.push_back({stones[i], i});
    }
    sort(ee.begin(), ee.end(), compare);
    auto eeiter = ee.begin();
    
    int answer = -1;
    unordered_map<int, int> deads;
    // idx X -> idx Y s.t. [X, Y] or [Y, X] is a range of dead stones
    
    vector<int> newdeads;
    for(;;) {
        newdeads.clear();
        int val = eeiter->first;
        while(eeiter != ee.end() && val == eeiter->first) {
            int idx = eeiter->second; ++eeiter;
            newdeads.push_back(idx);
        }
        
        for(int idx:newdeads) {
            auto itLeft = deads.find(idx-1);
            auto itRight = deads.find(idx+1);
            
            int lb=idx, rb=idx;
            if(itLeft != deads.end()) {
           		lb = itLeft->second;
                if(lb != idx-1) {
                    deads.erase(lb);
                }
                deads.erase(itLeft);
            }
            if(itRight != deads.end()) {
                rb = itRight->second;
                if(rb != idx+1) {
                    deads.erase(rb);
                }
                deads.erase(itRight);
            }
            
            if(rb-lb+1 >= k) {
                answer = val;
                break;
            }
            
            if(lb==rb) {
                deads.insert({lb, lb});
            } else {
                deads.insert({lb, rb});
                deads.insert({rb, lb});
            }
        }
        if(answer != -1) {
            break;
        }
    }
    return answer;
}
