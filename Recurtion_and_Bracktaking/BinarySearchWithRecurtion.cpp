#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&v,int star,int end,int tar){
    if(star<=end){
        int mid=star+(end-star)/2;
        if(v[mid]==tar){
            return mid;
        }
        else if(v[mid]<=tar){
          return  binarySearch(v,mid+1,end,tar);
        }
        else{
          return  binarySearch(v,star,mid-1,tar);
        }
    }
    return -1;
} 
int main(){
    int n,tar;
    cin>>n>>tar;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    cout<<binarySearch(v,0,n,tar);

}