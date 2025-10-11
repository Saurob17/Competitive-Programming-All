#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    string s;
    cin >> s;
    int n = s.length() + 1;

    int mid = n / 2;

    s[mid - 1] = '.';

    for(int i=0;i<n-1;i++){
        if(s[i]!='.'){
            cout << s[i];
        }
    }


}