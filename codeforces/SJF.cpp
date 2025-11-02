#include <bits/stdc++.h>
using namespace std;
//use comparetor
bool cmp(const pair<int,int> &a, const pair<int,int> &b){ 
    return a.first > b.first; 
}
int main(){
    int n; 
    cout << "Enter number of processes: "; cin >> n;
    vector<int> at(n), bt(n), wt(n), tat(n);
    cout << "Enter Arrival & Burst Time:\n";
    for(int i=0;i<n;i++) cin >> at[i] >> bt[i];

    vector<int> idx(n); iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int a,int b){ return at[a]<at[b]; });

    priority_queue<pair<int,int>,vector<pair<int,int>>,bool(*)(const pair<int,int>&,const pair<int,int>&)> pq(cmp);
    int time=0, done=0, i=0; double twt=0, ttat=0;
    vector<pair<int,int>> gantt;

    while(done<n){
        while(i<n && at[idx[i]]<=time) pq.push({bt[idx[i]],idx[i]}), i++;

        if(pq.empty()){ time++; continue; } 

        auto [b,id]=pq.top(); pq.pop();

        wt[id]=time-at[id]; tat[id]=wt[id]+bt[id];
        twt+=wt[id]; ttat+=tat[id]; time+=b; done++;
        gantt.push_back({id,time});
    }

    cout << "\nP\tAT\tBT\tWT\tTAT\n";
    for(int k=0;k<n;k++) cout<<"P"<<k+1<<"\t"<<at[k]<<"\t"<<bt[k]<<"\t"<<wt[k]<<"\t"<<tat[k]<<"\n";
    cout<<fixed<<setprecision(2);
    cout<<"\nAvg WT="<<twt/n<<"\nAvg TAT="<<ttat/n<<"\n\nGantt Chart:\n";
    cout<<"-----------------------------------\n";
    for(auto &g:gantt) cout<<"|   P"<<g.first+1<<" ";
    cout<<"|\n-----------------------------------\n0";
    for(auto &g:gantt) cout<<setw(7)<<g.second;
}
