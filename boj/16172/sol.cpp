#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> prekmp(string const& s) {
	vector<int> f(s.size()+1);
	f[0] = -1;
	int i = 0, j = -1;
	while (i < s.size()) {
		while (j != -1 && s[i] != s[j]) j = f[j];
		++i, ++j;
		if (s[i] == s[j]) f[i] = f[j];
		else f[i] = j;
	}
	return f;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, K;
	getline(cin, S);

	getline(cin, K);
	auto f = prekmp(K);

	int i = 0, j = 0;
	while(i<S.size()) {
		if('0'<=S[i] && S[i]<='9') {
			++i; continue;
		}
		while (j != -1 && S[i] != K[j]) j = f[j];
		++i, ++j;
		if (j == K.size()) {
			cout << "1\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}
