#include <bits/stdc++.h>
using namespace std;

int queary(int type, int l, int r)
{
    cout << type << " " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int left;
        int lo = 1, hi = n;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (queary(1, 1, mid) != queary(2, 1, mid))
            {
                left = mid;
                hi = mid - 1;
            }
            else
            {

                lo = mid + 1;
            }
        }

        int sump = queary(1, lo, n);
        int sumn = queary(2, lo, n);

        int diff = abs(sump - sumn);

        cout << "! " << left << " " << left + diff << endl;
    }
}
