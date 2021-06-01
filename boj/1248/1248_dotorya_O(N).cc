// source: https://www.acmicpc.net/source/567757
// Determining the order relation of prefix-sums!!!
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <tuple>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

bool X[15][15];
struct data {
	data() {
		data(0);
	}
	data(int x) {
		N = x;
	}
	int N;
	bool operator < (const data & l) const {
		return X[N][l.N];
	}
} D[15];

char d[120];

int sum[15];
int main() {
	int N, i, j;
	scanf("%d", &N);
	scanf("%s", d);
	int t = 0;
	for (i = 0; i < N; i++) {
		for (j = i+1; j <= N; j++) {
			if (d[t] == '+') X[i][j] = true;
			else if(d[t] == '-') X[j][i] = true;
			t++;
		}
	}
	for (i = 0; i <= N; i++) D[i] = data(i);
	sort(D, D + N + 1);

	sum[D[0].N] = 0;
	for (i = 1; i <= N; i++) {
		if (X[D[i - 1].N][D[i].N]) sum[D[i].N] = sum[D[i - 1].N] + 1;
		else sum[D[i].N] = sum[D[i - 1].N];
	}

	for (i = 1; i <= N; i++) printf("%d ", sum[i] - sum[i - 1]);
	return 0;
}
