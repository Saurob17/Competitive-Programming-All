#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
// pair<long long,long long> fib(long long n){return n?({auto p=fib(n/2);long long a=p.first,b=p.second,c=(a*((2*b%MOD-a+MOD)%MOD))%MOD,d=(a*a%MOD+b*b%MOD)%MOD; n%2?make_pair(d,(c+d)%MOD):make_pair(c,d);}):make_pair(0,1);}

// Returns pair {F(n), F(n+1)} % MOD
pair<long long, long long> fib(long long n)
{
    if (n == 0)
        return {0, 1};
    auto p = fib(n / 2);
    long long a = p.first;
    long long b = p.second;

    long long c = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD; // F(2k)
    long long d = (a * a % MOD + b * b % MOD) % MOD;           // F(2k+1)

    if (n % 2 == 0)
        return {c, d};
    else
        return {d, (c + d) % MOD};
}
int main()
{
    long long n;
    cin >> n;                     // Example: n = 1e6
    cout << fib(n).first << endl; // F(n) % MOD
    return 0;
}
