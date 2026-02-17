#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n),v1(n);

        for (int i = 0;i < n;i++)cin >> v[i],v1[i]=v[i];
        int cnt = 0;
        if (n == 1){
            cnt=0;
        }
        else if (n == 2) {
            if (v[0] == 7 - v[1] || v[0]==v[1])cnt++;
        }
        for (int i = 1;i < n - 1;i++) {
            int val = 1;
            bool ok = false;

            while (v[i - 1] == 7 - v[i] || v[i + 1] == 7 - v[i] 
                || v[i]==v[i+1] || v[i]==v[i-1]) {
                v[i] = val;
                val++;
                ok = true;

            }
            if (ok)cnt++;
        }
        int co=0;
        for (int i = 2;i < n - 1;i++) {
            int val = 1;
            bool ok = false;

            while (v1[i - 1] == 7 - v1[i] || v1[i + 1] == 7 - v1[i] 
                || v1[i]==v1[i+1] || v1[i]==v1[i-1]) {
                v1[i] = val;
                val++;
                ok = true;

            }
            if (ok)co++;
        }
        if(n%2==1){
             if(v1[n-1]==v1[n-2] || v1[n-1]==7-v1[n-2])co++;
        }
        if(v1[0]==v1[1] || v1[0]==7-v1[1])co++;
        cout<<min(co,cnt)<<endl;

    }
}