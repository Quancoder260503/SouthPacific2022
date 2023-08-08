#include "bits/stdc++.h"
using namespace std;
const int MAXN = (int)2e3 + 10;
const int inf = 1e7;
#define pii pair<int, int>
#define mp make_pair
int n, k;
int dp[MAXN][MAXN];
int a[MAXN], b[MAXN];
signed main(void)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i] >> a[i];
    }
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            if (j >= a[i])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
            }
        }
    }
    pii ans = mp(0, 0);
    for (int i = 0; i <= k; i++)
    {
        if(dp[n][i] == inf) continue;
        ans = max(ans, mp(i, -dp[n][i]));
    }
    cout << -ans.second << '\n'; 
    return 0;
}