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
int in[N];
int low[N];
int timer;
void dfs(int node, int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        else if (vis[it] == 1)
        {
            low[node] = min(low[node], in[it]);
            // edge node <-> child is a back edge
        }
        else
        {
            dfs(it, node);
            if (low[it] > in[node])
            {
                cout << it << "<->" << node << " is a bridge !" << endl;
            }
            low[node] = min(low[node], low[it]);
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
    dfs(1, -1);

    return 0;
}