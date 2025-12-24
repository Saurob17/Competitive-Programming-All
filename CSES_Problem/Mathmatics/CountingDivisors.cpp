#include <bits/stdc++.h>
using namespace std;

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

// 🔹 Function to return number of divisors of a number x
int numberOfDivisors(int x) {
    return divisors[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precomputeDivisors(); // Step 1: Precompute

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << numberOfDivisors(x) << "\n"; // Step 2: Answer queries
    }
}
