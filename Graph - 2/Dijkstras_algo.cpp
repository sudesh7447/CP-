#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
vector<pair<int, int>> adj[1000];

bool vis[100005];

void Dijkstra()
{
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dis(n + 1, INT_MAX);

    pq.push({0, 1});
    dis[1] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_d = pq.top().first;

        pq.pop();
        if (vis[cur])
        {
            continue;
        }

        vis[cur] = 1;
        for (auto it : adj[cur])
        {
            if (cur_d + it.second < dis[it.first])
            {
                dis[it.first] = cur_d + it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }
}
signed main()
{

    return 0;
}