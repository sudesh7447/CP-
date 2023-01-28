#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
bool vis[500][500];
int grid[500][500];
int dis[500][500];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
bool isValid(int x, int y)
{
    if (x < 0 | x >= N | y < 0 | y >= M)
    {
        return 0;
    }
    if (vis[x][y] == 1)
    {
        return 0;
    }
    if (grid[x][y] == 0)
    {
        return 0;
    }

    return 1;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

void BFS(int sx, int sy)
{
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(cx + dx[i], cy + dy[i]))
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                q.push({cx, cy});
                dis[nx][ny] = dis[cx][cy] + 1;
                vis[nx][ny] = 1;
            }
        }
    }
}
signed main()
{

    return 0;
}