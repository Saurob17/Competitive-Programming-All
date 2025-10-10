#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        int needSticks = (y * k) + k;
        

        int totalOP = (needSticks -1+ (x - 2)) / (x - 1);

        cout << totalOP+k << endl;
    }
}