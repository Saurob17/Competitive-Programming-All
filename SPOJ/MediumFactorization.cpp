#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
int spf[MAXN + 1];

void sieve() {
    for (int i = 1; i <= MAXN; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
     }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    while (cin >> n) {
        cout << 1;

        while (n > 1) {
            cout << " x " << spf[n];
            n /= spf[n];
        }
        cout << '\n';
    }
}
