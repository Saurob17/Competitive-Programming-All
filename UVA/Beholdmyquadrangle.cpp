#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        map<int,int>m;
        
        if(a==b && b==c && c==d){
            cout<<"square"<<endl;
        }
        else if(a==c && b==d){
            cout<<"rectangle"<<endl;
        }
        else {
            int mx=max(a,max(b,max(c,d)));
            int to=(a+b+c+d)-mx;
            if(to>mx){
                cout<<"quadrangle"<<endl;
            }
            else{
                cout<<"banana"<<endl;
            }

        }
    }
}