#include <bits/stdc++.h>
using namespace std;


bool isIdentifier(string s) {
    int state = 0;

    for (char c : s) {
        if (state == 0) {
            if (isalpha(c) || c == '_') state = 1;
            else return false;
        }
        else if (state == 1) {
            if (isalnum(c) || c == '_') state = 1;
            else return false;
        }
    }
    return (state == 1);
}

bool isInteger(string s) {
    int state = 0;

    for (char c : s) {
        if (state == 0) {
            if (isdigit(c)) state = 1;
            else return false;
        }
        else if (state == 1) {
            if (isdigit(c)) state = 1;
            else return false;
        }
    }
    return (state == 1);
}


bool isFloat(string s) {
    int state = 0;

    for (char c : s) {
        if (state == 0) {
            if (isdigit(c)) state = 1;
            else return false;
        }
        else if (state == 1) {
            if (isdigit(c)) state = 1;
            else if (c == '.') state = 2;
            else return false;
        }
        else if (state == 2) {
            if (isdigit(c)) state = 3;
            else return false;
        }
        else if (state == 3) {
            if (isdigit(c)) state = 3;
            else return false;
        }
    }
    return (state == 3); 
}


bool isOperator(string s) {
    vector<string> ops = {
        "+","-","*","/","=",
        "==","!=","<",">","<=",">="
    };

    for (auto op : ops) {
        if (s == op) return true;
    }
    return false;
}


int main() {
    string s;
    cin >> s;

    if (isIdentifier(s))
        cout << s << " is IDENTIFIER\n";
    else if (isFloat(s))
        cout << s << " is FLOAT CONSTANT\n";
    else if (isInteger(s))
        cout << s << " is INTEGER CONSTANT\n";
    else if (isOperator(s))
        cout << s << " is OPERATOR\n";
    else
        cout << s << " is INVALID\n";

    return 0;
}