#include <bits/stdc++.h>
using namespace std;
int main()
{
      ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n>>m;
    set<int> st;
    multiset<int> len;

    st.insert(n);
    st.insert(0);
    len.insert(n);


    while (m--)
    {
        /* code */
 
        int x;
        cin >> x;
        auto lf = st.lower_bound(x);
        lf--;

        auto ri = st.upper_bound(x);
        int dif = abs(*lf - *ri);
        auto i=len.find(dif);
        len.erase(len.find(dif));
        //cout<<" dif "<<dif<<endl;
        len.insert(x-*lf);
        len.insert(*ri-x);
        
        auto it=len.end();
        it--;
        cout<<*it<<" ";
    
        st.insert(x);
    }
}