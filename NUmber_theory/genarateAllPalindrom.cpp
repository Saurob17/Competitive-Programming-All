
#include <bits/stdc++.h>
using namespace std;


// ✅ Function to check if a string is palindrome
bool isPalindrome(const string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

// ✅ Convert integer `x` to base `base` and return as string
string toBase(long long x, int base) {
    if (x == 0) return "0";  // special case: 0
    string res = "";
    while (x > 0) {
        int digit = x % base;
        res = char('0' + digit) + res;  // prepend instead of reverse later
        x /= base;
    }
    return res;
}

// ✅ Generate all decimal palindromes ≤ limit (N)
vector<long long> generateDecimalPalindromes(long long limit) {
    vector<long long> pal;
    // 1 থেকে 6-digit half ব্যবহার করে 12-digit পর্যন্ত palindrome বানাবো
    for (int len = 1; len <= 6; len++) {
        long long start = pow(10, len - 1);
        long long end = pow(10, len) - 1;
        for (long long half = start; half <= end; half++) {
            string s = to_string(half);
            string rev = s;
            reverse(rev.begin(), rev.end());
            
            // odd length palindrome
            string odd = s + rev.substr(1);
            long long oddNum = stoll(odd);
            if (oddNum <= limit) pal.push_back(oddNum);
            
            // even length palindrome
            string even = s + rev;
            long long evenNum = stoll(even);
            if (evenNum <= limit) pal.push_back(evenNum);
        }
    }
    // single-digit palindromes (1–9)
    for (int i = 1; i <= 9; i++) {
        if (i <= limit) pal.push_back(i);
    }

    sort(pal.begin(), pal.end());
    pal.erase(unique(pal.begin(), pal.end()), pal.end());
    return pal;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A;
    long long N;
    cin >> A >> N;

    vector<long long> palindromes = generateDecimalPalindromes(N);

    long long sum = 0;
    for (auto x : palindromes) {
        string baseA = toBase(x, A);
        if (isPalindrome(baseA)) {
            sum += x;
        }
    }

    cout << sum << "\n";
    return 0;
}
