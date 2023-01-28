#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1e9 + 7
#define test  \
    int T;    \
    cin >> T; \
    while (T--)

const int N = 1e5;
vector<int> adj[N];
bool vis[N];
int dis[N];

void sssp(int node, int d)
{
    vis[node] = 1;
    dis[node] = d;

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            sssp(it, d + 1);
        }
    }
}

signed main()
{
    int n;
    cin >> n;
    int p;
    cin >> p;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sssp(p, 0);
    int q;
    cin >> q;
    int idx = INT_MAX;
    int ans = INT_MAX;
    while (q--)
    {
        int g;
        cin >> g;
        if (dis[g] <= ans)
        {
            ans = dis[g];
            idx = min(idx, g);
        }
    }
    cout << idx << endl;

    return 0;
}