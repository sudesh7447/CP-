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
int col[N];
bool bipartileDFS(int node, int c)
{
    vis[node] = 1;
    col[node] = c;
    for (auto child : adj[node])
    {
        if (vis[child] == 0)
        {
            if (bipartileDFS(child, c ^ 1) == false)
            {
                return false;
            }
        }
        else if (col[child] == col[node])
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    int ct = 1;
    test
    {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i <= n + 8; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < n + 8; i++)
        {
            col[i] = 0;
            vis[i] = 0;
        }

        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool x = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                x &= bipartileDFS(i, 0);
            }
        }

        cout << "Scenario #" << ct << ":" << endl;
        if (x)
        {
            cout << "No suspicious bugs found!" << endl;
        }
        else
        {
            cout << "Suspicious bugs found!" << endl;
        }
        ct++;
    }
    return 0;
}