#include "bits/stdc++.h"
using namespace std;
const int MAXN = (int)200;
int n, p, m;
int arr[MAXN];
int player[MAXN][MAXN];
int cnt[MAXN];
int cnt2[MAXN]; 
signed main(void)
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt2[arr[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            cin >> player[i][j];
        }
    }
    memset(cnt, 0, sizeof(cnt)); 
    for (int i = 1; i <= n; i++)
    {
        cnt[arr[i]]++;
        int finish = (i == n);
        for (int j = 1; j <= m; j++)
        {
            int good = 1;
            for (int k = 1; k <= p; k++)
            {
                good = good & (cnt[player[j][k]] >= 1);
            }
            if (good == 1)
            {
                finish = 1;
                break;
            }
        }
        if (finish)
        {
            for (int j = 1; j <= m; j++)
            {
                int good = 1;
                int lose = 0;
                for (int k = 1; k <= p; k++)
                {
                    good = good & (cnt[player[j][k]]  >= 1);
                    lose = lose || (cnt2[player[j][k]] == 0);
                }
                if (good == 1)
                {
                    puts("winning");
                }
                else if (lose)
                {
                    puts("hopeless");
                }
                else 
                {
                    puts("losing");
                }
            }
            break;
        }
    }
    return 0;
}