#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bitset<50000001> isComposite; // max for odd numbers up to 1e8

void sieve(int MAXN) {
    primes.push_back(2);

    for (int i = 3; 1LL * i * i <= MAXN; i += 2) {
        if (!isComposite[i / 2]) {
            for (int j = i * i; j <= MAXN; j += 2 * i)
                isComposite[j / 2] = 1;
        }
    }

    for (int i = 3; i <= MAXN; i += 2) {
        if (!isComposite[i / 2])
            primes.push_back(i);
    }
}

inline bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    return !isComposite[n / 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> queries(T);
    int maxN = 0;

    for (int i = 0; i < T; i++) {
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    sieve(maxN);   // 🔥 only required range

    for (int n : queries) {
        if (!isPrime(n)) {
            cout << -1 << '\n';
            continue;
        }

        int idx = lower_bound(primes.begin(), primes.end(), n) - primes.begin() + 1;

        long long row = (long long)ceil((sqrt(8.0 * idx + 1) - 1) / 2);
        long long prev = row * (row - 1) / 2;
        long long col = idx - prev;

        cout << row << " " << col << '\n';
    }

    return 0;
}
