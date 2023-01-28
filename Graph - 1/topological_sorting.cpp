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
vector<int> res;

// Directed Acyclic Graph

int Kahn(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        res.push_back(cur);
        q.pop();

        for (auto it : adj[cur])
        {
            in[it]--;
            if (in[it] == 0)
            {
                q.push(it);
            }
        }
    }

    cout << "TopoSort : ";
    for (int node : res)
    {
        cout << node << ' ';
    }
    cout << endl;
}
signed main()
{
    int n, m, x, y;
    cin >> n >> m ;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
        // x -> y
    }

    Kahn(n);

    return 0;
}