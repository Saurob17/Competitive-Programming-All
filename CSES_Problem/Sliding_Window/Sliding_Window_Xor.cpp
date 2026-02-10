#include<bits/stdc++.h>
using namespace std;
int main() {
    long long k, n;
    cin >> n >> k;

    long long x, a, b, c;
    cin >>x>> a >> b >> c;

    vector<long long>v(n);
    v[0] = x;

    for (int i = 1;i < n;i++) {
        v[i] = ((v[i - 1] * a) + b) % c;
    }   

    vector<long long>ans;
    int l = 0, r = k ;
    long long sum = v[0];
    for (int i = 1;i < k;i++) {
        sum ^= v[i];
    }
    long long temsum = sum;
    
    while (r < n)
    {
        /* code */
        
        temsum ^= v[r];
        temsum ^= v[l];
        l++;
        r++;
        sum ^= temsum;
    }
    cout << sum;
}
