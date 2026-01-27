#include <bits/stdc++.h>
using namespace std;

// Bangla explanation:
// সমাধানের মূল ধারণা:
// আমরা n = a + b হলে concatenation = concat(a,b) = a * 10^{len(b)} + b হয়।
// len(b) = L নির্ধারিলে এই মান = n*10^L - b*(10^L - 1)। এটি L ধরা অবস্থায় b যত ছোট হবে ফলও তত বড় হবে।
// তাই প্রতিটি L (L>=1) জন্য b এর সর্বনিম্ন মান যেটি L ডিজিটের (b_min = 10^{L-1}) তা নিলে সর্বোচ্চ হয়।
// শর্ত: b_min <= n-1 (অর্থাৎ b_min < n)। তাই pow10 (10^{L-1}) < n পর্যন্ত সব L চেষ্টা করে,
// প্রতিটি ক্ষেত্রে a = n - b_min এবং candidate string = to_string(a) + string('1' + zeros)
// গঠন করে, স্ট্রিংভাবেই তুলনা করে সবচেয়ে বড় বাছাই করি। এইভাবে আমরা বড় সংখ্যার জন্যও নিরাপদে কাজ করতে পারি।

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; if(!(cin>>s)) return 0;
    unsigned long long n = 0;
    for(char c: s) n = n*10 + (c - '0');

    string best = "0";
    unsigned long long pow10 = 1; // 10^{L-1}
    while (pow10 < n) {
        // b = pow10 (has length L = number of digits in pow10)
        unsigned long long b = pow10;
        unsigned long long a = n - b; // a >= 1 because b < n
        string a_str = to_string(a);
        string b_str = "1" + string((int)log10((double)pow10), '0');
        // The above log10 trick gives digits-1; but safer: build b_str from pow10
        // We'll instead construct b_str directly:
        b_str = to_string(b);
        string cand = a_str + b_str;
        // compare as big integers by string length then lexicographically
        if (cand.size() > best.size() || (cand.size() == best.size() && cand > best)) best = cand;
        // next power of 10, watch overflow
        if (pow10 > (unsigned long long)(1e19)) break;
        pow10 *= 10ULL;
    }

    cout << best << '\n';
    return 0;
}