#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
const int N = 1e5 + 7;
vector<int> adj[N];
bool vis[N];
int dis[N];
void dfs(int node, int d)
{
    vis[node] = 1;
    dis[node] = d;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, d + 1);
        }
    }
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    int root = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mx <= dis[i])
        {
            mx = dis[i];
            root = i;
        }
    }
    for (int i = 0; i <= n + 18; i++)
    {
        dis[i] = 0;
        vis[i] = 0;
    }
    dfs(root, 0);
    mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, dis[i]);
    }
    cout << "Diameter = " << mx << endl;

    return 0;
}