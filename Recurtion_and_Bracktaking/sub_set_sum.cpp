#include<bits/stdc++.h>
using namespace std;
void subsetSum(int idx,int sum,vector<int>&arr,int n,vector<int>&sumsubSet){
    if(idx==n){
        sumsubSet.push_back(sum);

        return;
    }
    subsetSum(idx+1,sum+arr[idx],arr,n,sumsubSet);

    subsetSum(idx+1,sum,arr,n,sumsubSet);

}
int main(){
    vector<int>sumsubSet;
    vector<int>arr={1,2,3,4};
    int n=4;
    subsetSum(0,0,arr,n,sumsubSet);
    for(auto it:sumsubSet){
        cout<<it<<" ";
         
    }
    cout<<endl;
    

}