#include "bits/stdc++.h"
using namespace std;
#define MAXN (int)1e6 + 10
vector<int> adj[MAXN];
int n;
int dp[MAXN];
void dfs(int u, int p)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        dp[u] += dp[v];
    }
    dp[u] += (dp[u] ? -1 : 1);
}
signed main(void)
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1] ? "Alice" : "Bob") << '\n';
    return 0;
}