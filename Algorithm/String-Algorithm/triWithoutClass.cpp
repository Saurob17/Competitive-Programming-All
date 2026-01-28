#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000; // Maximum number of nodes
int trie[MAXN][26];      // Child links
bool isEnd[MAXN];        // Terminal flags
int nodeCount = 1;       // Root = 0

//complexity: insert, search, startsWith: O(L) where L is length of the word/prefix
// -------------------- Insert Word --------------------
void insertWord(string s) {
    int cur = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0)
            trie[cur][idx] = nodeCount++;
        cur = trie[cur][idx];
    }
    isEnd[cur] = true;
}

//complexity: O(L)
// -------------------- Search Exact Word --------------------
bool searchWord(string s) {
    int cur = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0) return false;
        cur = trie[cur][idx];
    }
    return isEnd[cur]; // True if exact word ends here
}

//complexity: O(P)
// -------------------- Prefix Search --------------------
bool startsWith(string prefix) {
    int cur = 0;
    for (char c : prefix) {
        int idx = c - 'a';
        if (trie[cur][idx] == 0) return false;
        cur = trie[cur][idx];
    }
    return true; // prefix exists
}

//complexity: O(L)
// -------------------- Remove Word --------------------
bool removeWord(int cur, string s, int pos = 0) {
    if (pos == s.size()) {
        if (!isEnd[cur]) return false; // word not present
        isEnd[cur] = false;

        // If no children, this node can be deleted
        for (int i = 0; i < 26; i++)
            if (trie[cur][i] != 0) return false;
        return true; // Node can be deleted
    }

    int idx = s[pos] - 'a';
    int child = trie[cur][idx];
    if (child == 0) return false; // Word not present

    bool shouldDeleteChild = removeWord(child, s, pos + 1);

    if (shouldDeleteChild) {
        trie[cur][idx] = 0; // Remove the link

        // Check if current node can also be deleted
        if (isEnd[cur]) return false;
        for (int i = 0; i < 26; i++)
            if (trie[cur][i] != 0) return false;
        return true;
    }

    return false;
}

// -------------------- Reset Trie --------------------
void resetTrie() {
    memset(trie, 0, sizeof(trie));
    memset(isEnd, 0, sizeof(isEnd));
    nodeCount = 1;
}

// -------------------- Main --------------------
int main() {
    resetTrie(); // optional, ensure fresh trie

    insertWord("applee");
     insertWord("applee");
    insertWord("app");
    insertWord("applexx");
    insertWord("doesp");
    insertWord("aklldmf");

    cout << searchWord("applee") << endl;  // 1
    cout << searchWord("app") << endl;     // 1
    cout << searchWord("apple") << endl;   // 0
    cout << startsWith("app") << endl;     // 1
    cout << startsWith("doe") << endl;     // 1
    cout << startsWith("akl") << endl;     // 1
    cout << startsWith("xyz") << endl;     // 0
cout<<endl;
    removeWord(0, "applee");
    cout << searchWord("applee") << endl;  // 0
    cout << searchWord("app") << endl;     // 1

    return 0;
}
