#include<bits/stdc++.h>
using namespace std;
int missingNum(vector<int>&arr,int n){
    int misNum=arr[0];

    for(int i=0;i<n;i++){
        misNum=misNum^arr[i];
        misNum^=i;
    }
    misNum=misNum^n;
    return misNum;

}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
}