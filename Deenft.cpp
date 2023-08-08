#include "bits/stdc++.h"
using namespace std;
typedef long long lint;
const int MAXN = (int)1e6 + 10;
const lint mod = 1e18;
map<int, int> primes;
map<int, int> tprimes;
lint n, m, k, t;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k, m;
        cin >> m >> k;
        if (k > m - k)
        {
            k = m - k;
        }
        for (int j = m - k + 1; j <= m; j++)
        {
            int now = j;
            for (int p = 2; p * p <= now; p++)
            {
                while (now % p == 0)
                {
                    primes[p]++;
                    now = now / p;
                }
            }
            if (now > 1)
            {
                primes[now]++;
            }
        }
        for (int j = 1; j <= k; j++)
        {
            int now = j;
            for (int p = 2; p * p <= now; p++)
            {
                while (now % p == 0)
                {
                    primes[p]--;
                    now = now / p;
                }
            }
            if (now > 1)
            {
                primes[now]--;
            }
        }
        for (auto it : primes)
        {
            tprimes[it.first] += it.second;
        }
        primes.clear();
    }
    lint ans = 1;
    for (auto it : tprimes)
    {
        for (int i = 0; i < it.second; i++)
        {
            ans = ans * it.first;
            if (ans > (lint)1e9)
            {
                puts("BIG ENOUGH");
                return 0;
            }
        }
    }
    cout << ans << '\n';
}