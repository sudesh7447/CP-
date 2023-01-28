// Calculating subtree size using dfs in O(N)

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
int SubTreeSize[N];
int dfs(int node)
{
    vis[node] = 1;
    int cur_size = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            cur_size += dfs(it);
        }
    }
    return SubTreeSize[node] = cur_size;
}
signed main()
{

    return 0;
}