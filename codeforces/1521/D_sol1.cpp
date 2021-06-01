#include <cstdio>

int t, n, low[100011];

struct edge {
    int v, next;
    edge() {}
    edge(int _v, int _next)
    {
        v = _v;
        next = _next;
    }
} e[200011];

int head[100011], sz;

void init()
{
    memset(head, -1, sizeof(head));
    sz = 0;
}

void insert(int u, int v)
{
    e[++sz] = edge(v, head[u]);
    head[u] = sz;
}

struct link {
    int u, v;
} add[100011], del[100011];

int an, dn, ch[100011], chn, up[100011];

void dfs(int u, int f)
{
    for (int i = head[u]; ~i; i = e[i].next)
        if (e[i].v ^ f) {
            dfs(e[i].v, u);
        }
    chn = 0;
    for (int i = head[u]; ~i; i = e[i].next)
        if (e[i].v ^ f) {
            if (up[e[i].v])
                ch[++chn] = e[i].v;
            else
                ++dn, del[dn].u = u, del[dn].v = e[i].v;
        }
    if (chn >= 2) {
        up[u] = 0;
        ++an;
        add[an].u = low[ch[1]];
        add[an].v = low[ch[2]];
        for (int i = 3; i <= chn; ++i)
            ++dn, del[dn].u = u, del[dn].v = ch[i], ++an, add[an].u = ch[i], add[an].v = low[ch[i]];
        return;
    }
    else {
        up[u] = 1;
        if (chn)
            low[u] = low[ch[1]];
        else
            low[u] = u;
        return;
    }
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            head[i] = -1;
        sz = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            insert(u, v);
            insert(v, u);
        }
        an = dn = 0;
        dfs(1, 0);
        if (up[1])
            ++an, add[an].u = 1, add[an].v = low[1];
        int curend = add[1].v;
        printf("%d\n", dn);
        for (int i = 2; i <= an; ++i)
            printf("%d %d %d %d\n", del[i - 1].u, del[i - 1].v, curend, add[i].u), curend = add[i].v;
    }
    return 0;
}
