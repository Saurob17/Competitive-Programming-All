#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 🔹 Function: Sum of Divisors
ll sumOfDivisors(ll n) {
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            ll term = (pow(i, count + 1) - 1) / (i - 1);
            ans *= term;
        }
    }
    if (n > 1) ans *= (pow(n, 2) - 1) / (n - 1);
    return ans;
}

int main() {
    ll n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Sum of divisors = " << sumOfDivisors(n) << endl;
    return 0;
}
