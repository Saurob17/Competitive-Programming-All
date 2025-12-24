#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

bool isNotPrime[200011];
vector<int> divs[200011];
ll freq[200011];

void Solve()
{
    ll n;
    cin >> n;
    ll arr[n], brr[n];
    for (auto& it : arr)
        cin >> it;
    for (auto& it : brr)
        cin >> it;
    ll ans = 2;
    for (auto& it : arr) {
        for (auto& primeF : divs[it]) {
            freq[primeF]++;
            if (freq[primeF] >= 2) {
                ans = 0;
            }
        }
    }
    if (ans > 1)
        for (auto& it : arr) {
        
            for (auto& primeF : divs[it + 1]) {
                if (freq[primeF] != 0) {
                    ans = 1;
                }
            }
          
        }
    cout << ans << '\n';
    for (auto& it : arr) {
        for (auto& primeF : divs[it]) {
            freq[primeF]--;
        }
    }
}

int32_t main()
{
    for (ll i = 2; i <= 200010; i++)
        if (!isNotPrime[i])
            for (ll j = i; j <= 200010; j += i) {
                isNotPrime[i] = 1, divs[j].push_back(i);
            }
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        Solve();
    }
    return 0;
}
// Coded by Tahsin Arafat (@TahsinArafat)
// Coded for CPS Academy