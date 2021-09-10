#include <iostream>
using namespace std;
int N, a[100001], arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=1;i<=N;++i) {
		cin>>a[i];
		arr[i]=a[i];
		arr[i]+=arr[i-1];
	}
	int mn=a[N];
	for(int i=N-1;i>=2;--i) {
		if(mn>a[i]) {
			mn=a[i];
		}
		arr[i-1] += mn;
	}
	int a=0,b=1;
	for(int i=1;i<N-1;++i) {
		int aa=arr[N]-arr[i],bb=N-i-1;
		if(1LL*a*bb < 1LL*aa*b) {
			a=aa;
			b=bb;
		}
	}
	for(int i=1;i<N-1;++i) {
		if(1LL*a*(N-i-1) == 1LL*(arr[N]-arr[i])*b) {
			cout<<i<<'\n';
		}
	}
	return 0;
}
