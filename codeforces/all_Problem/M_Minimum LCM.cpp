#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    cin >> X;

    long long bestA = 1, bestB = X;
    long long bestMax = X;

    for (long long a = 1; a * a <= X; a++) {
        if (X % a == 0) {
            long long b = X / a;

            if (__gcd(a, b) == 1) {
                long long curMax = max(a, b);
                if (curMax < bestMax) {
                    bestMax = curMax;
                    bestA = a;
                    bestB = b;
                }
            }
        }
    }

    cout << bestA << " " << bestB << "\n";
    return 0;
}
