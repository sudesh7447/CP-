#include <bits/stdc++.h>
using namespace std;
// Pre-computing N log(N)
// query log(N)

// could be used to find distance between two trees in log(N) time
// dist between a and b = level[a] + level[b] - 2* LCA(a,b)
vector<int> adj[100005];
int LCA[1000][1000];
int level[100005];
void DFS(int node, int par)
{
    LCA[node][0] = par;
    for (int child : adj[node])
    {
        if (child != par)
        {
            DFS(child, node);
        }
    }
}


void BFS(int node, int par, int l)
{
    level[node] = l;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto it : adj[top])
        {
            if (it != par)
            {
                q.push(it);

                level[it] = level[top] + 1;
            }
        }
    }
}


int maxN, N;
void init()
{
    DFS(1, -1);
    BFS(1, -1, 0);
    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (LCA[i][j - 1] != -1)
            {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - i];
            }
        }
    }
}

int LCAF(int a, int b)
{
    if (level[a] > level[b])
    {
        swap(a, b);
    }
    int d = level[b] - level[a];
    // cout << d << endl;
    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }
    if (a == b)
    {
        return a;
    }

    for (int i = maxN; i >= 0; i--)
    {
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

int main()
{
    cin >> N;
    maxN = log2(N);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    init();
    for (int i = 0; i < N; i++)
    {
        cout << level[i + 1] << ' ';
    }

    cout << endl;

    cout << LCAF(4, 3) << endl;

    return 0;
}