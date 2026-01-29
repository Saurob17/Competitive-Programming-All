#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000000 + 5;

int trie[MAXN][26];
int passCount[MAXN];
int endCount[MAXN];
string bestWord[MAXN];
int bestCnt[MAXN];
int nodeCount = 1;

// ---------------- Insert ----------------
void insertWord(string s) {
    int cur = 0;
    passCount[cur]++;

    vector<int> path;
    path.push_back(cur);

    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0)
            trie[cur][idx] = nodeCount++;
        cur = trie[cur][idx];
        passCount[cur]++;
        path.push_back(cur);
    }

    endCount[cur]++;
    int finalCnt = endCount[cur];

    for (int node : path) {
        if (finalCnt > bestCnt[node] ||
           (finalCnt == bestCnt[node] &&
           (bestWord[node].empty() || s < bestWord[node]))) {
            bestCnt[node] = finalCnt;
            bestWord[node] = s;
        }
    }
}

// ---------------- Query ----------------
void queryPrefix(string s) {
    int cur = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0) {
            cout << "-1\n";
            return;
        }
        cur = trie[cur][idx];
    }

    if (bestCnt[cur] == 0) cout << "-1\n";
    else cout << bestWord[cur] << " " << bestCnt[cur] << "\n";
}

// ---------------- Reset ----------------
void resetTrie() {
    for (int i = 0; i < nodeCount; i++) {
        memset(trie[i], 0, sizeof(trie[i]));
        passCount[i] = 0;
        endCount[i] = 0;
        bestCnt[i] = 0;
        bestWord[i].clear();
    }
    nodeCount = 1;
}

// ---------------- Main ----------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    resetTrie();

    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        insertWord(s);
    }

    int q;
    cin >> q;

    while (q--) {
        cin >> s;
        queryPrefix(s);
    }

    return 0;
}
