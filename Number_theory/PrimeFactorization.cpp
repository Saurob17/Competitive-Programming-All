#include <bits/stdc++.h>
using namespace std;

void primeFactors(int n) {
    // Step 1: divide by 2
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Step 2: divide by odd numbers
    for (int i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Step 3: if remaining n > 2, it's prime
    if (n > 2) cout << n;
}

int main() {
    int n;
    cin >> n;
    primeFactors(n);
}
