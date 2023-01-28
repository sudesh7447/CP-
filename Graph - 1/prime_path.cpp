// https://www.spoj.com/problems/PPATH/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
const int N = 1e4 + 9;
vector<int> adj[N];
bool vis[N];
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
                q.push(it);
                dis[it] = dis[cur] + 1;
                vis[it] = 1;
            }
        }
    }
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
signed main()
{

    vector<int> pr;

    for (int i = 1000; i < 10000; i++)
    {
        if (isPrime(i))
        {
            pr.push_back(i);
        }
    }

    for (int i = 0; i < pr.size(); i++)
    {
        for (int j = i + 1; j < pr.size(); j++)
        {
            string p1 = to_string(pr[i]);
            string p2 = to_string(pr[j]);
            int ct = 0;
            for (int k = 0; k < 4; k++)
            {
                if (p1[k] != p2[k])
                {
                    ct++;
                }
            }
            if (ct == 1)
            {
                adj[pr[i]].push_back(pr[j]);
                adj[pr[j]].push_back(pr[i]);
            }
        }
    }

    test
    {
        int a, b;
        cin >> a >> b;
        for (int i = 1000; i < 10000; i++)
        {
            vis[i] = 0;
            dis[i] = 0;
        }
        BFS(a);
        cout << dis[b] << endl;
    }

    return 0;
}