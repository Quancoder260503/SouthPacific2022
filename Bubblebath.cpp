#include "bits/stdc++.h"
using namespace std;
#define MAXN (int)5e5 + 10
#define lint long long
struct fenwick
{
    int N;
    vector<int> bit;
    void init(int _N)
    {
        N = _N;
        bit.resize(N);
    }
    int sum(int i)
    {
        int c = 0;
        for (++i; i > 0; i -= (i & -i))
        {
            c = c + bit[i];
        }
        return c;
    }
    void upd(int i, int dif)
    {
        for (++i; i < N; i += (i & -i))
        {
            bit[i] = dif + bit[i];
        }
    }
} fenw;
int arr[MAXN];
int n;
int inv[MAXN];
lint res[MAXN];
signed main(void)
{
    cin >> n;
    vector<int> coor;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        coor.push_back(arr[i]);
    }
    sort(coor.begin(), coor.end());
    fenw.init(n + 2);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(coor.begin(), coor.end(), arr[i]) - coor.begin() + 1;
        int inversions = fenw.sum(n) - fenw.sum(pos);
        ans = max(ans, inversions);
        inv[inversions]++;
        fenw.upd(pos, 1);
    }
    cout << ans << '\n';
    for (int i = ans; i > 0; i--)
    {
        res[i] += res[i + 1] + inv[i];
    }
    for (int i = 1; i <= ans; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}