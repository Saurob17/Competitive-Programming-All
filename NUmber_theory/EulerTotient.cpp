#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euler's Totient Function
int phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;  // multiply by (1 - 1/p)
        }
    }
    if (n > 1)
        result -= result / n; // for last prime factor
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Euler's Totient ϕ(" << n << ") = " << phi(n) << endl;
    return 0;
}
//complexity = O(√n)
