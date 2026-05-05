#include <bits/stdc++.h>
using namespace std;

bool isLetter(char c) {
    return (isalpha(c));
}


bool isDigit(char c) {
    return (isdigit(c));
}

bool isValidIdentifier(string s) {
    int state = 0; 

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (state == 0) {
         
            if (isLetter(c) || c == '_') {
                state = 1; 
            } else {
                return false; 
            }
        }
        else if (state == 1) {
           
            if (isLetter(c) || isDigit(c) || c == '_') {
                state = 1;
            } else {
                return false;
            }
        }
    }

  
    return (state == 1);
}

int main() {
    string s;

    
    cin >> s;

    if (isValidIdentifier(s)) {
        cout << s << " is a VALID identifier" << endl;
    } else {
        cout << s << " is NOT a valid identifier" << endl;
    }

    return 0;
}