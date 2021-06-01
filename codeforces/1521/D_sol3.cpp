#include <cstdio>
#include <vector>
 
using namespace std;
 
int dfs(vector<vector<int>> &g, int x, int p, vector<pair<int,int>> &d, vector<pair<int,int>> &a)
{
	int cnt = 0;
	int z = -1;
	for (int i = 0; i < g[x].size(); ++i)
	{
		int v = g[x][i];
		if (v != p)
		{
			int u = dfs(g, v, x, d, a);
			if (u == -1)
				d.push_back(pair<int,int>(v, x));
			else
			{
				if (cnt == 0)
					z = u;
				else if (cnt == 1)
				{
					a.push_back(pair<int,int>(z, u));
					z = -1;
				}
				else
				{
					d.push_back(pair<int,int>(v, x));
					a.push_back(pair<int,int>(v, u));
				}
				++cnt;
			}
		}
	}
	if (cnt == 0)
		return x;
	else
		return z;
}
 
void solve()
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<pair<int,int>> d;
	vector<pair<int,int>> a;
	/*for (int i = 0; i < n; ++i)
		if (g[i].size() == 1)
		{
			dfs(g, i, -1, i, d, a);
			break;
		}*/
	int z = dfs(g, 0, -1, d, a);
	if (z != -1)
		a.push_back(pair<int,int>(0,z));
	int r = d.size();
	printf("%d\n", r);
	//for (int i = 0; i < a.size(); ++i)
	//	printf("(%d %d)\n", a[i].first+1,a[i].second+1);
	for (int i = 0; i < r; ++i)
	{
		printf("%d %d %d %d\n", d[i].first+1, d[i].second+1, a[i].second+1, a[i+1].first+1);
	}
}
 
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
		solve();
	return 0;
}
