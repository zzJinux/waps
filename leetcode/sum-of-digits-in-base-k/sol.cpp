class Solution {
public:
    int sumBase(int n, int k) {
        int w;
        int ans=0;
        for(w=k; n;) {
            ans+=n%w;
            n/=k;
        }
        return ans;
    }
};
