#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e3 + 10;
int n, m;
char g[MAXN][MAXN];
int good[MAXN];
signed main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        bool ok = 1;
        for (int j = 1; j < n; j++)
        {
            ok = ok & (g[j][i] == g[j + 1][i]);
        }
        good[i] = ok;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!good[i])
            continue;
        int now = i;
        while (now <= m && good[now])
        {
            now++;
        }
        ans = max(ans, now - i);
    }
    cout << ans << '\n';
    return 0;
}