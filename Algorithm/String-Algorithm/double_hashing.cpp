// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// const ll MOD1 = 1000000007;
// const ll MOD2 = 1000000009;
// const ll P = 31;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string s, good;
//     int k;
//     cin >> s >> good >> k;

//     int n = s.size();

//     // Prefix sum of bad letters
//     vector<int> bad(n+1, 0);
//     for (int i = 0; i < n; i++) {
//         int idx = s[i] - 'a';
//         if (good[idx] == '0') bad[i+1] = 1;
//     }
//     for (int i = 1; i <= n; i++) bad[i] += bad[i-1];

//     // Precompute powers
//     vector<ll> pow1(n+1, 1), pow2(n+1, 1);
//     for (int i = 1; i <= n; i++) {
//         pow1[i] = (pow1[i-1] * P) % MOD1;
//         pow2[i] = (pow2[i-1] * P) % MOD2;
//     }

//     // Prefix hashes
//     vector<ll> h1(n+1, 0), h2(n+1, 0);
//     for (int i = 0; i < n; i++) {
//         h1[i+1] = (h1[i] * P + (s[i] - 'a' + 1)) % MOD1;
//         h2[i+1] = (h2[i] * P + (s[i] - 'a' + 1)) % MOD2;
//     }

//     auto getHash = [&](int l, int r) -> pair<ll,ll> {
//         ll x1 = (h1[r] - h1[l] * pow1[r-l] % MOD1 + MOD1) % MOD1;
//         ll x2 = (h2[r] - h2[l] * pow2[r-l] % MOD2 + MOD2) % MOD2;
//         return {x1, x2};
//     };

//     // Store distinct good substrings using pair hash
//     set<pair<ll,ll>> st;
//     for (int l = 0; l < n; l++) {
//         for (int r = l+1; r <= n; r++) {
//             int bad_count = bad[r] - bad[l];
//             if (bad_count <= k) {
//                 st.insert(getHash(l, r));
//             }
//         }
//     }

//     cout << st.size() << "\n";
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// দুইটা বড় prime modulus
const long long mod1 = 1000000007;
const long long mod2 = 1000000009;
const long long base = 131;   // সাধারণত prime base নেওয়া হয়
// maximum size (string length পর্যন্ত)
const int N = 1000005;
long long hash1[N], hash2[N];       // prefix hash
long long pow1[N], pow2[N];         // power array
// Power precompute (base^i % mod)
void precompute(int n) {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow1[i] = (pow1[i-1] * base) % mod1;
        pow2[i] = (pow2[i-1] * base) % mod2;
    }
}
// Hash build function
void buildHash(string &s) {
    int n = s.size();
    hash1[0] = hash2[0] = 0;
    for (int i = 1; i <= n; i++) {
        hash1[i] = (hash1[i-1] * base + s[i-1]) % mod1;
        hash2[i] = (hash2[i-1] * base + s[i-1]) % mod2;
    }
}
// substring hash পাওয়ার function
pair<long long,long long> getHash(int l, int r) {
    // s[l..r], 1-indexed
    long long x1 = (hash1[r] - (hash1[l-1] * pow1[r-l+1]) % mod1 + mod1) % mod1;
    long long x2 = (hash2[r] - (hash2[l-1] * pow2[r-l+1]) % mod2 + mod2) % mod2;
    return {x1, x2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    // Precompute power
    precompute(n);

    // Build hash
    buildHash(s);

    // Example: substring compare
    // compare s[l1..r1] with s[l2..r2]
    int l1 = 1, r1 = 3;   // substring s[1..3]
    int l2 = 4, r2 = 6;   // substring s[4..6]

    auto h1 = getHash(l1, r1);
    auto h2 = getHash(l2, r2);

    if (h1 == h2) cout << "Substrings are equal\n";
    else cout << "Not equal\n";

    return 0;
}  