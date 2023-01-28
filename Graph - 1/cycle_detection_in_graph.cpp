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
bool has_cycle(int node, int parent)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (has_cycle(it, node) == true)
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}
signed main()
{

    return 0;
}