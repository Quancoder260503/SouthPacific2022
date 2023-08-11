#include "bits/stdc++.h"
using namespace std;
#define MAXN (int)2e6 + 10
vector<int> adj[MAXN];
int n;
int g[MAXN];
void dfs(int u, int p, int root = 1)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == p) continue;
        dfs(v, u, root); 
        g[u] += (g[v] == 0);
    }
    if (u != root && adj[u].size() == 1)
    {
        g[u] = 1;
    }
    return;
}
void dfs2(int u, int p)
{
    if (p)
    {
        if(adj[u].size() == 1)
        {
            g[u] = (g[p] == 0);
        }
        else 
        {
            if(adj[p].size() > 1)
            {
                g[u] += (g[p] == (g[u] == 0));
            }
        }
    }
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == p) continue;
        dfs2(v, u);
    }
    return;
}
signed main(void)
{
    scanf("%d", &n);
    if(n == 1)
    {
        printf("%d\n", n); 
        return 0;
    }
    if(n == 2)
    {
        printf("%d\n", 0);
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (g[i] != 0);
    }
    printf("%d\n", ans);
    return 0;
}