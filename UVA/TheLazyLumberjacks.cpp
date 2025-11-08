#include<bits/stdc++.h>
using namespace std;
bool isTrianle(int a,int b,int c){
    return (a+b>c && a+c>b && b+c>a);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(isTrianle(a,b,c)){
            cout<<"OK"<<endl;
        }
        else{
            cout<<"Wrong!!"<<endl;
        }
    }
}