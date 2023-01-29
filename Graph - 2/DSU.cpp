#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)

int parent[10005];
int Size[10005];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}

signed main()
{

    return 0;
}