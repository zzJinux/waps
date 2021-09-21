#include <iostream>
using namespace std;

int N;
int arr[501];
int dp[500][500];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin>>tc;
	while(tc--) {
		cin>>N;
		for(int i=1;i<=N;++i) {
			cin>>arr[i];
			arr[i]+=arr[i-1];
		}
		for(int l=1;l<N;++l) {
			for(int i=0;i+l<N;++i) {
				int val=0x7fFFffFF;
				for(int ll=0;ll<l;++ll) {
					int v = dp[ll][i] + dp[l-ll-1][i+ll+1] + arr[i+l+1] - arr[i];
					if(val > v) {
						val = v;
					}
				}
				dp[l][i]=val;
			}
		}
		cout<<dp[N-1][0]<<'\n';
	}
	return 0;
}
