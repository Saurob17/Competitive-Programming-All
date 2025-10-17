#include <bits/stdc++.h>
using namespace std;
#define int long long
int lcm(vector<int> &a)
{
    int ans = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        ans = (ans * a[i]) / __gcd(ans, a[i]);
    }
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        int original = n;
        map<int, int> m;
        vector<int> a;
        while (n > 0)
        {
            if (n % 10 > 1 && m[n % 10] == 0)
            {
                m[n % 10] = 1;
                a.push_back(n % 10);
            }
            n /= 10;
        }
        int div = 1;
        if (m[2] == 1 && (m[4] == 1 || m[8 == 1]))
        {
            div *= 2;
        }
        if (m[3] == 1 && m[9] == 1)
        {
            div *= 3;
        }
        if (m[4] == 1 && m[8] == 1)
        {
            div *= 4;
        }

        if (a.empty())
        {
            cout << original << endl;
            continue;
        }

        int divis = 1;
        for (int x : a)
        {
            divis *= x;
        }

        divis = divis / div;
cout << divis << " " << original % divis << endl;
        if (original % divis == 0)
        {
            cout << original << endl;
        }
        else
        {
            cout << original + (divis - (original % divis)) << endl;
        }
    }
}