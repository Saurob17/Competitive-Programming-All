#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// মোট ক্যারেক্টার সংখ্যা অনুযায়ী MAXN নির্ধারণ
const int MAXN = 500005; 
int trie[MAXN][26];
int passCount[MAXN];
int nodeCount = 1;

// শব্দ ইনসার্ট করার ফাংশন
void insertWord(const string& s) {
    int cur = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0) {
            trie[cur][idx] = nodeCount++;
        }
        cur = trie[cur][idx];
        passCount[cur]++; // এই নোড দিয়ে কয়টি শব্দ গিয়েছে
    }
}

// সর্বোচ্চ LCP খোঁজার ফাংশন
int getMaxLCP(const string& s) {
    int cur = 0;
    int lcp = 0;
    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';
        cur = trie[cur][idx];
        // যদি এই নোড দিয়ে ১টির বেশি শব্দ গিয়ে থাকে, তবে এটি একটি কমন প্রিফিক্স
        if (passCount[cur] > 1) {
            lcp = i + 1;
        } else {
            break; // আর কোনো কমন শব্দ নেই
        }
    }
    return lcp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        insertWord(words[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << getMaxLCP(words[i]) << "\n";
    }

}