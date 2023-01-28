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

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto it : adj[cur])
        {
            if (!vis[it])
            {
                q.push(it);
                dis[it] = dis[cur] + 1;
                vis[it] = 1;
            }
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
    BFS(1);
    cout << dis[n] << endl;

    return 0;
}