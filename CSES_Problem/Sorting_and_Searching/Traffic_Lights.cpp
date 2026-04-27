#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n>>m;
    set<int> st;
    multiset<int> ans;

    st.insert(n);
    st.insert(0);
    ans.insert(n);


    while (m--)
    {
        /* code */
 
        int x;
        cin >> x;
        auto lf = st.lower_bound(x);
        lf--;

        auto ri = st.upper_bound(x);
        int dif = abs(*lf - *ri);
        auto i=ans.find(dif);
        if(i!=ans.end()){
            ans.erase(i);
        }
     
        //cout<<" dif "<<dif<<endl;
        ans.insert(x-*lf);
        ans.insert(*ri-x);
        
        auto it=ans.end();
        it--;
        cout<<*it<<" ";
    
        st.insert(x);
    }
}