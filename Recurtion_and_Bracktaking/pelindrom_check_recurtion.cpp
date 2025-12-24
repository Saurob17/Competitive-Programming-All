#include<bits/stdc++.h>
using namespace std;
bool check(string &s,int n,int i){
    if(i>=(n/2))return true;
    if(s[i]!=s[n-1-i]){
        return false;
    }
    return check(s,n,i+1);
}
int main(){
    string s="cabac";
    cout<<endl;
    int n=s.size();
    
    
    cout<<check(s,n,0)<<endl;

}