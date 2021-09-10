#include <iostream>
#include <algorithm>
using namespace std;
int N; pair<int,int> arr[100000];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin>>N;
	long long w=0;
	for(int i=0;i<N;++i) {
		cin>>arr[i].first>>arr[i].second;
		w-=arr[i].second;
	}
	sort(arr, arr+N);
	int i;
	for(i=0;i<N;++i) {
		w += arr[i].second*2;
		if(w>=0) break;
	}
	cout<<arr[i].first;
	return 0;
}
