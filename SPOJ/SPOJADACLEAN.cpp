

#include <bits/stdc++.h>
using namespace std;

const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9, base = 131;
long long h1[1000005], h2[1000005], p1[1000005], p2[1000005];
void precompute(int n)
{
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; i++)
        p1[i] = p1[i - 1] * base % mod1, p2[i] = p2[i - 1] * base % mod2;
}
void buildHash(string &s)
{
    int n = s.size();
    for (int i = 1; i <= n; i++)
        h1[i] = (h1[i - 1] * base + s[i - 1]) % mod1, h2[i] = (h2[i - 1] * base + s[i - 1]) % mod2;
}
pair<long long, long long> getHash(int l, int r) { return {(h1[r] - (h1[l - 1] * p1[r - l + 1]) % mod1 + mod1) % mod1, (h2[r] - (h2[l - 1] * p2[r - l + 1]) % mod2 + mod2) % mod2}; }
int main()
{
    int t;
    cin >> t;
    precompute(1e5 + 10);
    while (t--)
    {

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        buildHash(s);

        map<pair<long long, long long>, int> mp;
        long long l = 1, r = k;
        while (r <= n)
        {
            auto it = getHash(l, r);
            mp[{it.first, it.second}] = 1;
            l++;
            r++;
        }
        cout << mp.size() << endl;
    }
}
