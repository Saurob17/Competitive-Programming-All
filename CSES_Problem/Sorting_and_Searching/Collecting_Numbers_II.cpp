#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> v(n+1),pos(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        pos[v[i]]=i;
    }

    int ans=1;

    for(int i=2;i<=n;i++)
        if(pos[i]<pos[i-1]) ans++;

    while(m--)
    {
        int a,b;
        cin>>a>>b;

        int x=v[a],y=v[b];

        set<int> s;
        s.insert(x);
        s.insert(x-1);
        s.insert(y);
        s.insert(y-1);

        for(auto i:s)
            if(i>=1 && i<n)
                if(pos[i]>pos[i+1]) ans--;

        swap(v[a],v[b]);
        swap(pos[x],pos[y]);

        for(auto i:s)
            if(i>=1 && i<n)
                if(pos[i]>pos[i+1]) ans++;

        cout<<ans<<"\n";
    }
}