#include <string>
#include <vector>
using namespace std;
bool isPossible(int n, const vector<int>& stones, int k) {
    int currLength = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - n <= 0)
            currLength++;
        else
            currLength = 0;
        if (currLength >= k)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int lo = 1;
    int hi = 200000000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if(mid == 5) {
        }
        if (isPossible(mid, stones, k))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}
