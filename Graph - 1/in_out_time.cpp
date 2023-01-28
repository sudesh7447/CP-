#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
const int N = 1e5;
vector<int> adj[N];
bool vis[N];
int in[N];
int out[N];
int t;
void dfs(int node)
{
    vis[node] = 1;
    in[node] = t++;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
    out[node] = t++;
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    t = 0;
    dfs(0);

    return 0;
}