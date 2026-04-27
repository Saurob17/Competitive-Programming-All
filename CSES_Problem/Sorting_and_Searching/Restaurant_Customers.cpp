#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){

    int n;
    cin >> n;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    ordered_set st;

    int ans = 0;
int cnt = st.order_of_key(7);

    for(int i=0;i<n;i++){

        int a = v[i].first;
        int b = v[i].second;

        // remove customers who already left
        while(!st.empty() && *st.begin() <= a){
            st.erase(st.begin());
        }

        st.insert(b);

        ans = max(ans,(int)st.size());
    }

    cout << ans;
}