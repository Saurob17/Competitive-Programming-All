#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
map<ll, ll> m;
ll f = 0;
void dfs(ll n, ll b)
{

    if (m.count(n) || n > b)
    {
        return;
    }
    if (n == b)
    {
        f = 1;
        cout << "YES" << endl;
        v.push_back(n);
        return;
    }
    m[n] = 1;

    dfs(n * 2, b);
    if (f)
    {
        v.push_back(n);
        return;
    }
    dfs((n * 10) + 1, b);
    if (f)
    {
        v.push_back(n);
        return;
    }
}
int main()
{
    m.clear();
    ll a, b;
    cin >> a >> b;
    dfs(a, b);
    if (!f)
    {
        cout << "NO";
    }
    else
    {
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for (auto it : v)
        {
            cout << it << " ";
        }
    }
}