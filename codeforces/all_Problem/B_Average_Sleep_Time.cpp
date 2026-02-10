#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    long long sum = 0, tot = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for (int i = 0;i < k;i++) {
        sum += v[i];
    }
    tot = sum;
    int l = 0, r = k;

    while (r < n) {
        tot -= v[l];
        tot += v[r];
        sum += tot;
        l++;
        r++;
    }

    long double ans = (long double)sum / (long double)(n - k + 1);
    cout << fixed << setprecision(10) << ans << endl;

}