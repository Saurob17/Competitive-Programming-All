// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// // 🔹 Function: Sum of Divisors
// ll sumOfDivisors(ll n) {
//     ll ans = 1;
//     for (ll i = 2; i * i <= n; i++) {
//         ll count = 0;
//         while (n % i == 0) {
//             n /= i;
//             count++;
//         }
//         if (count > 0) {
//             ll term = (pow(i, count + 1) - 1) / (i - 1);
//             ans *= term;
//         }
//     }
//     if (n > 1) ans *= (pow(n, 2) - 1) / (n - 1);
//     return ans;
// }

// int main() {
//     ll n;
//     cout << "Enter n: ";
//     cin >> n;
//     cout << "Sum of divisors = " << sumOfDivisors(n) << endl;
//     return 0;
// }
 



#include <bits/stdc++.h>
using namespace std;
using int128 = __int128_t;
 
const int MAXP = 1e8 + 5;
vector<int> primes;
 
// Bitwise Sieve to generate all primes up to MAXP
vector<bool> is_prime(MAXP, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * 1LL * i < MAXP; i++) {
        if (is_prime[i]) {
            for (int j = i * 1LL * i; j < MAXP; j += i) is_prime[j] = false;
        }
    }
    for (int i = 2; i < MAXP; i++) if (is_prime[i]) primes.push_back(i);
}
 
// Multiply carefully using __int128_t
int128 sum_of_divisors(__int128 n) {
    __int128 ans = 1;
    __int128 temp = n;
 
    for (int p : primes) {
        if (1LL * p * p > n) break;
        if (n % p == 0) {
            __int128 term = 1;
            __int128 pow_p = 1;
            while (n % p == 0) {
                n /= p;
                pow_p *= p;
                term += pow_p;
            }
            ans *= term;
        }
    }
    if (n > 1) ans *= (n + 1); // n itself is prime
    return ans - temp; // proper divisors sum
}
 
// Print __int128_t safely
void print_int128(int128 x) {
    if (x == 0) { cout << 0 << "\n"; return; }
    string s;
    while (x > 0) { s.push_back('0' + x % 10); x /= 10; }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    sieve(); // Precompute primes up to 1e8
 
    int T;
    cin >> T;
    while (T--) {
        long long n_input;
        cin >> n_input;
        if (n_input == 1) {
            cout << 0 << "\n";
            continue;
        }
        __int128 n = n_input;
        print_int128(sum_of_divisors(n));
    }
}
 