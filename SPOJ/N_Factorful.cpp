#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int cnt[MAX];

int prefix[11][MAX];

void precompute()
{

    for (int i = 2; i < MAX; i++)
    {

        if (cnt[i] == 0)
        { // i is prime

            for (int j = i; j < MAX; j += i)

                cnt[j]++;
        }
    }

    for (int n = 0; n <= 10; n++)
    {
        prefix[n][0] = 0;
        for (int i = 1; i < MAX; i++)
        {
            prefix[n][i] = prefix[n][i - 1] + (cnt[i] == n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int T;

    cin >> T;

    while (T--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        cout << (prefix[n][b] - prefix[n][a - 1]) << "\n";
    }

   
}