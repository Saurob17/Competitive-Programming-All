#include<bits/stdc++.h>
using namespace std;
int main(){


    unordered_map<int ,int>mp;

    mp[1]=10;
    mp[2]=20;
    mp[3]=30;
mp.at(2)--;

    for(auto &it:mp){
        cout<<it.first<<" "<<it.second<<"\n";
    }
//search key and return iterator to that key
    if(mp.find(1)==end(mp)){
        cout<<"Not Found\n";
    }
    else{
        cout<<"Found "<<mp[1]<<"\n";
    }


 //delete spacific key
    mp.erase(2);



}