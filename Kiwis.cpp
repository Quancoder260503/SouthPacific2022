#include "bits/stdc++.h"
using namespace std;
const int MAXN = 101;
const int SZ = 10;
bool sanc[4];
int g[MAXN][MAXN];
int arr[MAXN];
int n;
int player[MAXN];
void print()
{
    for (int j = 0; j < 4; j++)
    {
        cout << min(101, player[j]) << " ";
    }
    cout << '\n';
}
bool chk()
{
    for (int j = 0; j < 4; j++)
    {
        if (player[j] <= 100)
            return 0;
    }
    return 1;
}
signed main(void)
{
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            cin >> g[i][j];
        }
    }
    int sz = 0;
    for (int i = SZ - 1; i >= 0; i--)
    {
        if (i & 1)
        {
            for (int j = 0; j < SZ; j++)
            {
                arr[++sz] = g[i][j];
            }
        }
        else
        {
            for (int j = SZ - 1; j >= 0; j--)
            {
                arr[++sz] = g[i][j];
            }
        }
    }
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        player[i] = 1;
    }
    int cnt = 0, start = 0;
    while (true)
    {
        int now = start % 4;
        start++;
        if (player[now] > 100)
        {
            continue;
        }
        if (sanc[now])
        {
            sanc[now] = 0;
            continue;
        }
        int move;
        cin >> move;
        cnt++;
        player[now] += move;
        if (arr[player[now]] == -1)
        {
            sanc[now] = 1;
        }
        if (player[now] <= 100 && arr[player[now]] > 0)
        {
            player[now] = arr[player[now]];
        }
        if (chk() || cnt == n)
        {
            print();
            return 0;
        }
    }
    return 0;
}