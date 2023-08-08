#include "bits/stdc++.h"
using namespace std;
#define MAXN 250000
#define x first
#define y second
typedef long double ldb;
typedef pair<ldb, ldb> Vec;
const int mod = 1e9 + 7;
int n, k;
using Point = Vec;
vector<Point> lower, upper;
Point P[MAXN];
Vec operator-(Vec AB, Vec AC)
{
    return Vec(AB.x - AC.x, AB.y - AC.y);
}
ldb cross(Vec AB, Vec AC)
{
    return (ldb)AB.x * AC.y - (ldb)AB.y * AC.x;
}
ldb cross3(Point A, Point B, Point C)
{
    Vec X = B - A;
    Vec Y = C - A;
    return cross(X, Y);
}
void ConvexHull(vector<Point> &Pset)
{
    sort(Pset.begin(), Pset.end());
    Pset.erase(unique(Pset.begin(), Pset.end()), Pset.end());
    int n = Pset.size();
    // lower hull
    vector<Point> hull;
    for (int i = 0; i < n; i++)
    {
        while (hull.size() > 1 && cross3(hull[hull.size() - 2], hull.back(), Pset[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(Pset[i]);
    }
    // upper hull
    int lower_hull = hull.size();
    lower = hull;
    for (int i = n - 2; i >= 0; i--)
    {
        while (hull.size() > lower_hull && cross3(hull[hull.size() - 2], hull.back(), Pset[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(Pset[i]);
    }
    for (int i = lower_hull - 1; i < hull.size(); i++)
    {
        upper.push_back(hull[i]);
    }
    reverse(upper.begin(), upper.end());
    return;
}
ldb get_y(const Point &a, const Point &b, ldb x)
{
    ldb numer = (a.y - b.y) * (x - a.x);
    ldb denom = (a.x - b.x);
    return (ldb)(numer / denom + a.y);
}
ldb Area(vector<Point> &Pset)
{
    int sz = Pset.size();
    ldb ans = 0;
    for (int i = 0; i < sz; i++)
    {
        ans += Pset[i].x * Pset[(i + 1) % sz].y - Pset[(i + 1) % sz].x * Pset[i].y;
    }
    ans = ans / 2;
    ans = fabsl(ans); 
    return ans;
}
ldb f(ldb xt)
{
    auto it = lower_bound(upper.begin(), upper.end(), Point(xt, 0));
    auto it2 = lower_bound(lower.begin(), lower.end(), Point(xt, 0));
    ldb yt, yt2;
    if (it != upper.begin())
    {
        yt = get_y(*prev(it), *it, xt);
    }
    if (it2 != lower.begin())
    {
        yt2 = get_y(*prev(it2), *it2, xt);
    }
    ldb P = 0, P2 = 0;
    int pos = it - upper.begin();
    int pos2 = it2 - lower.begin();
    vector<Point> p;
    vector<Point> p2;
    p.push_back(Point(xt, yt));
    for (int i = pos; i < upper.size(); i++)
    {
        p.push_back(upper[i]);
    }
    for (int i = lower.size() - 1; i >= pos2; i--)
    {
        p.push_back(lower[i]);
    }
    p.push_back(Point(xt, yt2));
    p2.push_back(Point(xt, yt));
    for (int i = pos - 1; i >= 0; i--)
    {
        p2.push_back(upper[i]);
    }
    for (int i = 0; i < pos2; i++)
    {
        p2.push_back(lower[i]);
    }
    p2.push_back(Point(xt, yt2));
    P = Area(p), P2 = Area(p2);
    return fabsl(P - P2);
}
signed main(void)
{
    cin >> n;
    vector<Point> Pset;
    ldb left = 1e9;
    ldb right = -1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i].y >> P[i].x;
        left = min(left, P[i].x);
        right = max(right, P[i].x);
        Pset.push_back(P[i]);
    }
    ConvexHull(Pset);
    ldb oldleft = left; 
    left++;
    right--;
    for (int i = 1; i <= 100; i++)
    {
        ldb x1 = (2 * left + right) / 3.0;
        ldb x2 = (left + 2 * right) / 3.0;
        if (f(x1) < f(x2))
            right = x2;
        else
            left = x1;
    }
    cout << setprecision(10) << left - oldleft << '\n';
    return 0;
}
/*
    rotate by 90
    use ternary search
*/
