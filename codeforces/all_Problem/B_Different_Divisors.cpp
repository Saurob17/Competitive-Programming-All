#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int add1 = 1 + n;

        int ans;
        int add2 = 1;
        add2 = (2 * n)+1;
        ans = add2 * add1;
        cout << ans << endl;
    }
}