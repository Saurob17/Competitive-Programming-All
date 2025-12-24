#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(const vector<int> &v)
{
    int n = v.size();
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num = num * 2 + v[i]; // left shift + add bit
    }
    return num;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
     int n;
        cin >> n;

        vector<long long> v(n);
        long long g = 0;
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<long long> vc;
        int ans;

        for (int i = 0; i < n - 1; i++)
        {
            if (v[i + 1] % v[i] == 0)
                continue;
            else
            {
                long long lc=v[i] / __gcd(v[i], v[i + 1]);
                vc.push_back(lc);
            }
        }
        if (vc.size() == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            ans = vc[0];
            for (auto it : vc)
            {
                ans = ans * it / (gcd(ans, it));
            }
            cout << ans << endl;
        }
    }
}