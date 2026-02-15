#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int,null_type,less<int>,rb_tree_tag,
            tree_order_statistics_node_update> ordered_set;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    while(T--){
        int n,k;
        cin >> n >> k;

        vector<int> a(n);
        for(int &x: a) cin >> x;

        ordered_set os;

        // initial remaining part
        for(int i=k;i<n;i++)
            os.insert(a[i]);

        int sum = 0;
        int m = n - k;

        for(int i=0;i<(m+1)/2;i++)
            sum += *os.find_by_order(i);

        int ans = 2*sum - (m%2 ? *os.find_by_order(m/2) : 0);

        int l=0, r=k;

        while(r<n){

            int pos = os.order_of_key(a[r]);

            if(pos < (os.size()+1)/2)
                sum -= a[r];
            else
                sum -= *os.find_by_order((os.size()-1)/2);

            os.erase(a[r]);

            os.insert(a[l]);
            pos = os.order_of_key(a[l]);

            if(pos < (os.size()+1)/2)
                sum += a[l];
            else
                sum += *os.find_by_order((os.size()-1)/2);

            ans = max(ans, 
                2*sum - (m%2 ? *os.find_by_order(m/2) : 0)
            );

            l++; 
            r++;
        }

        cout << ans << "\n";
    }
}
