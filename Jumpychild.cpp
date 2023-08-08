#include "bits/stdc++.h"
using namespace std;
const int MAXN = (int)2e3 + 1;
const int inf = 1e7;
int arr[MAXN];
map<int,int>mp;
int n, d, w;
signed main(void)
{
    cin >> n >> d >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    sort(arr + 1, arr + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= d)
        {
            ans += n - i + 1;
            break;
        }
        int good = 0;
        int now;
        for (auto it : mp)
        {
            if (it.first * d >= w * arr[i])
            {
                good = 1;
                now = it.first;
                break;
            }
        }
        if (!good)
        {
            ans += n - i + 1;
            break;
        }
        else
        {
            mp[now]--; 
            if(mp[now] == 0) mp.erase(now); 
        }
    }
    cout << ans << '\n';
    return 0;
}