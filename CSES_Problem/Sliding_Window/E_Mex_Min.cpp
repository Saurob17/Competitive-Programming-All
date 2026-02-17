#include<bits/stdc++.h>
using namespace std;
vector<int>mp;
void remake(int n){
mp.resize(n+2,0);
}
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
remake(n);
    vector<int>v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }

    for (int i = 0;i <= k;i++) {
        p.insert({ 0,i });
    }
    vector<int>ans;
    int an=INT_MAX;
    for (int i = 0;i < n;i++) {
        addValu(v[i]);

        if (i >= k) {
            removValu(v[i - k]);
        }
        if (i >= k - 1) {
            an=min(an,mex());

        }
    }
    cout<<an;
    

}