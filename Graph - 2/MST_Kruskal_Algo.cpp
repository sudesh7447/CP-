#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
struct edge
{
    int a;
    int b;
    int w;
};
int par[100005];
int Size[10005];
bool comp(edge a, edge b)
{
    if (a.w < b.w)
    {
        return 1;
    }
    return 0;
}
int find(int v)
{
    if (v == par[v])
    {
        return v;
    }
    return par[v] = find(par[v]);
}
void Union(int a, int b)
{
    par[a] = b;
}
signed main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    edge adj[n];
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        adj[i].a = a;
        adj[i].b = b;
        adj[i].w = w;
    }
    sort(adj, adj + m, comp);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        a = find(adj[i].a);
        b = find(adj[i].b);
        if (a != b)
        {
            sum += adj[i].w;
            Union(a, b);
        }
    }

    return 0;
}