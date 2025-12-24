#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 5;
int divisors[MAXN];
// 🔹 Function to precompute number of divisors for all numbers up to MAXN
void precomputeDivisors() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j]++;
        }
    }
}

// 🔹 Function: Number of Divisors
ll numberOfDivisors(ll n) {
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        ans *= (count + 1);
    }
    if (n > 1) ans *= 2;
    return ans;
}

int main() {
    ll n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of divisors = " << numberOfDivisors(n) << endl;
    return 0;
}
