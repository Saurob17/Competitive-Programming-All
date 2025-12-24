#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int N = 1e6 + 5;
    vector<int> v(N, 0);

    // Precompute divisor count
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            v[j]++;
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        int g = __gcd(x, y);
        cout << v[g] << '\n';
    }
}
