#include <stdio.h>
#include <memory.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
const int N = 200005;
int g = 0, lx1[N] = { 0 }, ly1[N] = { 0 }, lx2[N] = { 0 }, ly2[N] = { 0 }, id = 0;
vector<int> my[N];
 
void push(int x1, int y1, int x2, int y2) {
    lx1[g] = x1;
    ly1[g] = y1;
    lx2[g] = x2;
    ly2[g] = y2;
    g ++;
}
 
int dfs(int x, int f) {
    int m1 = 0, m2 = 0, i = 0, y = 0, cnt = 0, m = 0;
    for (i = 0; i < my[x].size(); i ++) {
        y = my[x][i];
        if (y == f) continue;
        m = dfs(y, x);
        if (m == 0) {
        }
        else {
            cnt ++;
            if (cnt == 1) {
                m1 = m;
            }
            else if (cnt == 2) {
                m2 = m;
            }
            else {
                push(x, y, m, id);
                id = y;
            }
        }
        
    }
    if (cnt == 0) {
        return x;
    }
    else if (cnt == 1) {
        return m1;
    }
    else {
        push(x, f, m1, id);
        id = m2;
        return 0;
    }
}
 
void solve() {
    int i = 0, n = 0, p = 0, q = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i ++) {
        my[i].clear();
    }
    for (i = 1; i < n; i ++) {
        scanf("%d%d", &p, &q);
        my[p].push_back(q);
        my[q].push_back(p);
    }
    for (i = 1; i <= n; i ++) {
        if (my[i].size() == 1) break;
    }
    id = i;
    g = 0;
    dfs(id, 0);
    printf("%d\n", g);
    for (i = 0; i < g; i ++) {
        printf("%d %d %d %d\n", lx1[i], ly1[i], lx2[i], ly2[i]);
    }
    
}
 
int main() {
    int o = 1;
    scanf("%d", &o);
    while (o --) {
        solve();
        //fflush(stdout);
    }
    return 0;
}
