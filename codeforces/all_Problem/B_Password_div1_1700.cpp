#include <bits/stdc++.h>
using namespace std;

const long long mod1 = 1000000007;
const long long mod2 = 1000000009;
const long long base = 131;
const int N = 1000005;

long long hash1[N], hash2[N], pow1[N], pow2[N];

void precompute(int n) {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow1[i] = (pow1[i-1] * base) % mod1;
        pow2[i] = (pow2[i-1] * base) % mod2;
    }
}

void buildHash(string &s) {
    int n = s.size();
    hash1[0] = hash2[0] = 0;
    for (int i = 1; i <= n; i++) {
        hash1[i] = (hash1[i-1] * base + s[i-1]) % mod1;
        hash2[i] = (hash2[i-1] * base + s[i-1]) % mod2;
    }
}

pair<long long,long long> getHash(int l, int r) {
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

    precompute(n);
    buildHash(s);

    vector<int> candidates; // prefix == suffix lengths
    for (int len = 1; len < n; len++) {
        if (getHash(1, len) == getHash(n-len+1, n)) {
            candidates.push_back(len);
        }
    }

    int ansLen = 0;
    for (int len : candidates) {
        // check if prefix of length len appears in the middle
        for (int i = 2; i+len-1 < n; i++) {
            if (getHash(i, i+len-1) == getHash(1, len)) {
                ansLen = max(ansLen, len);
                break;
            }
        }
    }

    if (ansLen == 0) cout << "Just a legend\n";
    else cout << s.substr(0, ansLen) << "\n";

    return 0;
}
