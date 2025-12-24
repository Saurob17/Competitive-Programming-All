#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

bitset<MAXN / 2 + 1> isComposite;

void bitwiseSieve() {
    isComposite.reset();   // সবাইকে prime ধরে নিচ্ছি

    for (int i = 3; i * i <= MAXN; i += 2) {
        if (!isComposite[i / 2]) {  // i prime হলে
            for (int j = i * i; j <= MAXN; j += 2 * i) {
                isComposite[j / 2] = 1; // composite mark
            }
        }
    }
}
int main() {
    bitwiseSieve();

    cout << 2 << " ";   // 2 একমাত্র even prime

    for (int i = 3; i <= MAXN; i += 2) {
        if (!isComposite[i / 2]) {
            cout << i << " ";
        }
    }

    return 0;
}
