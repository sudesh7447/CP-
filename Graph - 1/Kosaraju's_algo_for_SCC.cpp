#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
vector<int> adj[5005];
vector<int> tr[5005];

vector<int> order;
vector<int> scc;

bool vis[5005];

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
    order.push_back(node);
}

void dfs1(int node)
{
    vis[node] = 1;
    for (auto it : tr[node])
    {
        if (!vis[it])
        {
            dfs1(it);
        }
    }
    scc.push_back(node);
}
signed main()
{
    for (int i = 0; i < 5000; i++)
    {
        adj[i].clear();
        tr[i].clear();
        vis[i] = 0;
        order.clear();
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        tr[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[order[n - i]])
        {
            scc.clear();
            dfs1(order[n - i]);
            cout << "dfs1() called from " << order[n - i] << " scc == " << endl;
            for (auto it : scc)
            {
                cout << it << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}