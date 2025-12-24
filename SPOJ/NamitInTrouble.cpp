// #include <bits/stdc++.h>
// using namespace std;

// const int MAXP = 100000;
// vector<long long> primeSquares;

// void sieve() {
//     vector<bool> isPrime(MAXP + 1, true);
//     isPrime[0] = isPrime[1] = false;

//     for (int i = 2; i <= MAXP; i++) {
//         if (isPrime[i]) {
//             primeSquares.push_back(1LL * i * i);
//             for (long long j = 1LL * i * i; j <= MAXP; j += i)
//                 isPrime[j] = false;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     sieve();

//     int T;
//     cin >> T;
//     while (T--) {
//         long long N, K;
//         cin >> N >> K;

//         int total = 0, liked = 0;
//         for (long long sq : primeSquares) {
//             if (sq > N) break;
//             total++;
//             if (sq > K) liked++;
//         }

//         cout << total << " " << liked << "\n";
//     }
//     return 0;
// }

