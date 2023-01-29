#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &e, int S)
    {
        vector<int> d(V, 100000000);
        d[S] = 0;
        vector<int> p(V, -1);
        int x;
        for (int i = 0; i < V; i++)
        {
            x = -1;
            for (int j = 0; j < e.size(); j++)
            {
                if (d[e[j][0]] < 100000000)
                {
                    if (d[e[j][1]] > d[e[j][0]] + e[j][2])
                    {
                        d[e[j][1]] = max(-100000000, d[e[j][0]] + e[j][2]);
                        p[e[j][1]] = e[j][0];
                        x = e[j][1];
                    }
                }
            }
        }

        if (x == -1)
        {
            return d;
        }
        else
        {
            return {-1};
        }
    }
};
signed main()
{

    return 0;
}