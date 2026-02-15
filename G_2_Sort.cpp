#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long>v(n);
        for (int i = 0;i < n;i++)cin >> v[i];

        vector<int>seq(n, 0);

        
        for (int i = 0;i < n - 1;i++) {
            if (v[i + 1] * 2 > v[i]) {
                seq[i + 1] = 1;
            }
        }
        int f = 0;

        for (int i = 1;i < n;i++) {
            if (seq[i] == 1) {
                seq[i] += seq[i - 1];
            }
           
        }
        int c = 0;

        for (int i = 0;i < n;i++) {
            if (seq[i] >= k)c++;
        }
        cout << c << endl;



    }
}