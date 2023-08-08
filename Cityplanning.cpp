#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
set<int> adj[MAXN];
int to[MAXN];
int dp[MAXN];
void bfs()
{
    memset(dp, -1, sizeof(dp));
    queue<int> q;
    dp[1] = 0;
    q.push(1);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vector<int> out;
        for (auto it : adj[to[u]])
        {
            if (dp[it] != -1)
            {
                out.push_back(it);
            }
            else
            {
                dp[it] = dp[u] + 1;
                q.push(it);
            }
        }
        for (auto it : out)
        {
            adj[to[u]].erase(it);
        }
    }
}
signed main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++)
        {
            int x;
            cin >> x;
            adj[i].insert(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> to[i];
    }
    bfs();
    cout << dp[n] << '\n';
    return 0;
}