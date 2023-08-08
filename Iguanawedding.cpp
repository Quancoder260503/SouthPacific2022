#include "bits/stdc++.h"
using namespace std;
const int MAXN = (int)2e5 + 10;
vector<int> adj[MAXN];
vector<int> fadj[MAXN];
int in[MAXN], low[MAXN], fa[MAXN];
string arr[MAXN][2];
map<string, int> mp;
bool vis[MAXN];
int deg[MAXN];
vector<int> S;
int component;
vector<int> comp[MAXN];
int n, m;
int timer = 1;
string ans[MAXN];
int flip(int x)
{
    return x & 1 ? x + 1 : x - 1;
}
void dfs(int u)
{
    in[u] = low[u] = timer++;
    S.push_back(u);
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (vis[v])
            continue;
        if (!in[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], in[v]);
    }
    if (in[u] == low[u])
    {
        component++;
        while (true)
        {
            int v = S.back();
            S.pop_back();
            fa[v] = component;
            comp[fa[v]].push_back(v);
            vis[v] = 1;
            if (u == v)
                break;
        }
    }
}
signed main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        mp[arr[i][0]] = 2 * i - 1;
        mp[arr[i][1]] = 2 * i;
    }
    for (int i = 1; i <= m; i++)
    {
        string a, b;
        cin >> a >> b;
        int u = mp[a], v = mp[b]; 
        adj[v].push_back(flip(u));
        adj[u].push_back(flip(v)); 
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (fa[2 * i] == fa[2 * i - 1])
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes"); 
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j];
            if (fa[i] == fa[v]) continue;
            fadj[fa[i]].push_back(fa[v]);
            deg[fa[v]]++;
        }
    }
    queue<int> q;
    vector<int> ord;
    for (int i = 1; i <= component; i++)
    {
        if (deg[i] == 0)
        {
            ord.push_back(i);
            q.push(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < fadj[u].size(); i++)
        {
            int v = fadj[u][i];
            deg[v]--;
            if (deg[v] == 0)
            {
                q.push(v);
                ord.push_back(v);
            }
        }
    }
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < ord.size(); i++)
    {
        int u = ord[i];
        for (int j = 0; j < comp[u].size(); j++)
        {
            int v = comp[u][j];
            int w = (v + 1) / 2;
            if (!vis[w])
            {
                ans[w] = (v & 1 ? arr[w][0] : arr[w][1]);
                vis[w] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    cout << '\n';
    return 0;
}