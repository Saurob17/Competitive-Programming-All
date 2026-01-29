#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int trie[MAXN][26];
int passCount[MAXN];   // how many words pass this node
int endCount[MAXN];    // how many words end here
int nodeCount = 1;

// -------------------- Insert --------------------
void insertWord(string s) {
    int cur = 0;
    passCount[cur]++;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0)
            trie[cur][idx] = nodeCount++;
        cur = trie[cur][idx];
        passCount[cur]++;
    }
    endCount[cur]++;
}

// -------------------- Search --------------------
bool searchWord(string s) {
    int cur = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0) return false;
        cur = trie[cur][idx];
    }
    return endCount[cur] > 0;
}

// -------------------- Prefix --------------------
bool startsWith(string s) {
    int cur = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0) return false;
        cur = trie[cur][idx];
    }
    return true;
}

// -------------------- Remove --------------------
void removeWord(string s) {
    if (!searchWord(s)) return;

    int cur = 0;
    passCount[cur]--;

    for (char c : s) {
        int idx = c - 'a';
        int next = trie[cur][idx];

        passCount[next]--;

        if (passCount[next] == 0) {
            trie[cur][idx] = 0;
            return;
        }

        cur = next;
    }
    endCount[cur]--;
}

// -------------------- Reset --------------------
void resetTrie() {
    memset(trie, 0, sizeof(trie));
    memset(passCount, 0, sizeof(passCount));
    memset(endCount, 0, sizeof(endCount));
    nodeCount = 1;
}

// -------------------- Main --------------------
int main() {
    resetTrie();

    insertWord("appla");
    insertWord("apple");
    insertWord("tpple");
    insertWord("xpple");
for(int i=0;i<1000;i++){
    cout<<passCount[i]<<" ";
}
cout<<endl;
    removeWord("apple");
    removeWord("apple");

    cout << searchWord("apple") << endl; // ✅ still 1

    removeWord("apple");
    removeWord("apple");

    cout << searchWord("apple") << endl; // ✅ now 0
}
