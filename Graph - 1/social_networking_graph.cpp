// https://www.codingninjas.com/codestudio/problems/social-networking-graph_1082557?leftPanelTab=0

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
int level[N];
int dis[N];
void BFS(int node)
{
    queue<int> q;
    vis[node] = 1;
    dis[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto it : adj[cur])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                dis[it] = dis[cur] + 1;
                level[dis[it]]++;
                q.push(it);
            }
        }
    }
}
vector<int> socialNetwork(vector<pair<int, int>> queries, int n, int e, int m, vector<pair<int, int>> edges)
{
    for (int i = 0; i < e; i++)
    {
        int x = edges[i].first;
        int y = edges[i].second;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            vis[i] = 0;
            dis[i] = 0;
            level[i] = 0;
        }
        int s, d;
        s = queries[j].first;
        d = queries[j].second;
        BFS(s);
        cout << level[d] << endl;
    }
}
signed main()
{
    int n, e;
    cin >> n >> e;

    int m;
    cin >> m;

    return 0;
}