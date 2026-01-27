#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;
const long long sombbobna = 1e18;

long long fmn(long long n, long long k)
{

    if (n == k)
    { return 0;

    }
       

    if (n < k){
         return sombbobna;
    }

    if (mp.count(n))
    {
          return mp[n];
    }
    

    long long flo = n / 2;
    long long se = (n + 1) / 2;

    long long res = 1 + min(fmn(flo, k), fmn(se, k));

    if (res >= sombbobna)
    {
         res = sombbobna;
    }

    return mp[n] = res;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        mp.clear();
        long long n, k;
        cin >> n >> k;
        long long ans = fmn(n, k);

        if (ans >= sombbobna)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}