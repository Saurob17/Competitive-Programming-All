#include<bits/stdc++.h>
using namespace std;

// Trie Node class
class TriNood {
public:
    char data;                     // বর্তমান অক্ষর
    TriNood* children[26];         // ২৬টা লিংক (A-Z)
    bool isTerminal;               // word শেষ হয়েছে কিনা

    // Constructor
    TriNood(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) 
            children[i] = NULL;    // শুরুতে সব NULL
        isTerminal = false;        // শুরুতে কোন word শেষ নয়
    }
};

// Trie class
class Trie {
public:
    TriNood* root;                 // Trie এর root

    Trie() {
        root = new TriNood('\0');  // root এ dummy character
    }

    // Recursive insert function
    void insertUtil(TriNood* root, string word) {

        // ✅ Base case: word শেষ
        if (word.length() == 0) {
            root->isTerminal = true;   // word complete mark
            return;
        }

        // বর্তমান character এর index বের করা
        int index = word[0] - 'A';
        TriNood* child;

        // ✅ যদি আগে থেকেই থাকে
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // ✅ না থাকলে নতুন node বানানো
            child = new TriNood(word[0]);
            root->children[index] = child;
        }

        // ✅ বাকি অংশ নিয়ে recursion
        insertUtil(child, word.substr(1));
    }

    // Insert wrapper
    void insert(string word) {
        insertUtil(root, word);
    }

    // Recursive search function
    bool searchUtil(TriNood* root, string word) {

        // ✅ Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TriNood* child;

        // ✅ যদি character থাকে
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;  // না থাকলে word নাই
        }

        // ✅ বাকি অংশ নিয়ে recursion
        return searchUtil(child, word.substr(1));
    }

    // Search wrapper
    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};

int main() {

    Trie* t = new Trie();

    // Insert word
    t->insert("ABCD");

    // Search
    cout << t->searchWord("ABCD") << endl; // 1
    cout << t->searchWord("ABC") << endl;  // 0

    return 0;
}
