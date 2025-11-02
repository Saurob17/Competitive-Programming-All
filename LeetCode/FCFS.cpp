#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
int main() {
    int n;
    cin >> n;
    vector<int> at(n), bt(n), wt(n), tat(n), ct(n);
    for (int i = 0; i < n; i++) cin >> at[i] >> bt[i];

    priority_queue<pair<int,int>, vector<pair<int,int>>, bool(*)(const pair<int,int>&, const pair<int,int>&)> pq(cmp);
    for(int i=0;i<n;i++) pq.push({at[i],i});

    int time=0; double twt=0, ttat=0;
    vector<pair<int,int>> gantt;
    while(!pq.empty()){
        auto [a,id] = pq.top(); pq.pop();

     
        if(time < a){
            gantt.push_back({0,a}); // 0 -> idle
            time = a;
        }
        wt[id] = time - at[id];
        time += bt[id];
        ct[id] = time;
        tat[id] = ct[id] - at[id];
        twt += wt[id]; ttat += tat[id];

        gantt.push_back({id+1, time});
    }

    cout<<"P\tAT\tBT\tCT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]
            <<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";

    cout<<fixed<<setprecision(2)<<"\nAvg WT="<<twt/n<<"\nAvg TAT="<<ttat/n<<"\n\n";

   
    cout<<"Gantt Chart:\n| ";
    for(auto &g:gantt){
        if(g.first==0) cout<<"IDLE   |  ";
        else cout<<"P"<<g.first<<"   |  ";
    }
    cout<<"\n0";
    for(auto &g:gantt) cout<<"\t"<<g.second;
    cout<<"\n";
}
