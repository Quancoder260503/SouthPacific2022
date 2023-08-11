#include "bits/stdc++.h"
using namespace std;
#define pii pair<int, int>
#define mp make_pair
const int MAXN = (int)2e5 + 10;
const int inf = 1e7;
int L[MAXN], R[MAXN];
int n;
pii ans;
int solve(int Left, int Right)
{
    if (Left >= Right)
    {
        return 1;
    }
    int good = 0; 
    for (int l = Left, r = Right; l <= r; l++, r--)
    {
        if (L[l] <= Left && Right <= R[l])
        {
            good = 1; 
            if (solve(Left, l - 1) && solve(l + 1, Right))
            {
                return 1;
            }
        }
        if (L[r] <= Left && Right <= R[r])
        {
            good = 1; 
            if (solve(Left, r - 1) && solve(r + 1, Right))
            {
                return 1;
            }
        }
    }
    if(!good)
    {
        cout << "No" << " " << Left << " " << Right << "\n";
        exit(0); 
    }
    return 0;
}
signed main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> L[i] >> R[i];
    }
    solve(1, n);
    puts("Yes"); 
    return 0;
}