#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    vector<int>v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    map<int, int>mp;
    int c = 0;
    for (int i = 0;i < k;i++) {
        if (mp[v[i]] == 0)c++;
        mp[v[i]]++;
    }
    int l = 0, r = k;
    cout << c << " ";
    while (r < n) {
        if (mp[v[l]] == 1) c--;
        mp[v[l]]--;
        if (mp[v[r]] == 0) c++;
        mp[v[r]]++,
            l++;
        r++;
        cout << c << " ";
    }
}