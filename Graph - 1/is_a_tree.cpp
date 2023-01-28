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
void dfs(int node)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            c++;
            dfs(i);
        }
    }
    if (c == 1 && n - 1 == m)
    {
        cout << "Tree" << endl;
    }
    else
    {
        cout << "NOT A TREE" << endl;
    }

    return 0;
}