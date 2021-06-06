#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Sieve {
	vector<bool> isprime;
	vector<int> primes;
	Sieve(int N): isprime(N+1) {
		int SQ=sqrt(N);
		for(int i=2;i<=SQ;++i) isprime[i]=true;
		for(int i=2;i<=SQ;++i) {
			if(!isprime[i]) continue;
			primes.push_back(i);
			for(int j=i*i; j<=SQ; j+=i) {
				isprime[j]=false;
			}
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M,arr[50000];
	int cc[50000];
	cin>>N>>M;
	int Smx=0;
	for(int i=0;i<N;++i) {
		cin>>arr[i];
		if(arr[i]%7!=0 || arr[i]%49==0) {
			cout<<-1<<'\n';
			return 0;
		}
		arr[i]/=7;
		if(Smx<arr[i]) Smx=arr[i];
	}
	Sieve sv(Smx);

	int ans=0;
	for(int p:sv.primes) {
		if(p==7) continue;
		for(int j=0;j<N;++j) cc[j]=0;
		int cum=0;
		for(int i=0;i<N;++i) {
			cum -= cc[i];
			int pc=0;
			while(arr[i]%p==0) {arr[i]/=p; ++pc;}
			int diff=pc-cum;
			if(diff > 0) {
				ans += diff;
				cum = pc;
				if(i+M<N) cc[i+M] = diff;
			}
		}
	}
	int ccl=0;
	for(int i=0; i<N; ++i) {
		if(arr[i]!=1) cc[ccl++]=i;
	}
	sort(cc, cc+ccl, [&](int a, int b) {
		return arr[a]<arr[b] || (arr[a]==arr[b] && a<b);
	});

	int pv=0;
	int from=-1;
	for(int i=0; i<ccl; ++i) {
		int idx=cc[i];
		if(arr[idx]!=pv) {
			pv=arr[idx];
			from=idx;
			++ans;
		}
		else if(idx-from+1>M) {
			from=idx;
			++ans;
		}
	}

	cout<<ans<<'\n';
	return 0;
}
