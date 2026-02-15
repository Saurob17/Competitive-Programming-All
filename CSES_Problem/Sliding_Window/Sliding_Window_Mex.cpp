#include<bits/stdc++.h>
using namespace std;
map<int, int>mp;
set<pair<int, int>>p;
void addValu(int x) {
    int fr = mp[x];
    if (fr == 0) {
        p.erase({ 0,x });
        p.insert({ 1,x });
        mp[x]++;
    }
    else {
        p.erase({ fr,x });

        p.insert({ fr + 1,x });
        mp[x]++;
    }
}

void removValu(int x) {
    int fr = mp[x];
    if (fr == 1) {
        mp[x]--;
        p.erase({ fr,x });
        p.insert({ 0,x });
    }
    else {
        p.erase({ fr,x });
        p.insert({ fr - 1,x });
        mp[x]--;
    }
}


int mex() {
    return p.begin()->second;
}


int main() {
    int n, k;
    cin >> n >> k;

    vector<int>v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }

    for (int i = 0;i <= k;i++) {
        p.insert({ 0,i });
    }
    vector<int>ans;
    for (int i = 0;i < n;i++) {
        addValu(v[i]);

        if (i >= k) {
            removValu(v[i - k]);
        }
        if (i >= k - 1) {
            ans.push_back(mex());
        }
    }
    for (auto it : ans) {
        cout << it << " ";
    }

}