// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
const int N = 1e6 + 7;
vector<int> adj[N];
bool vis[N];
int cc[N];
int id;

void dfs(int node)
{
    cc[node] = id;
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
    test
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n + 10; i++)
        {
            adj[i].clear();
            vis[i] = 0;
            cc[i] = 0;
        }

        vector<pair<int, int>> v;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            string s;
            cin >> x >> s >> y;
            if (s == "=")
            {
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            else
            {
                v.push_back({x, y});
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                id++;
            }
        }
        bool ans = true;
        for (int i = 0; i < v.size(); i++)
        {
            if (cc[v[i].first] == cc[v[i].second])
            {
                ans = false;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}