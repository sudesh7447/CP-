// Fire Escape Routes
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

void dfs(int node, int &ct)
{
    vis[node] = 1;
    ct++;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, ct);
        }
    }
}
signed main()
{
    test
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        for (int i = 0; i < n + 10; i++)
        {
            vis[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int count = 0;
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                count++;
                int ct = 0;
                dfs(i, ct);
                ans *= ct;
            }
        }
        cout << count << ' ' << ans << endl;
    }
    return 0;
}