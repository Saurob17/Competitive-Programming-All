#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;

    ll minx, miny, maxx, maxy;
    minx = INT_MAX;
    miny = INT_MAX;
    maxx = INT_MIN;
    maxy = INT_MIN;


    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }

    cout<<(max(abs(maxy-miny),abs(maxx-minx))+1)/2<<endl;
}