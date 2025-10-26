#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
 
    cin >> n;

    int at[20], bt[20], wt[20], tat[20], ct[20], start[20];

   
    for(int i = 0; i < n; i++)
        cin >> at[i] >> bt[i];

   
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++)
        pq.push({-at[i], i}); 

    int time = 0;
    vector<int> order;

    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int idx = p.second;

        if(time < at[idx]) time = at[idx]; // CPU idle
        start[idx] = time;
        wt[idx] = time - at[idx];
        ct[idx] = time + bt[idx];
        tat[idx] = wt[idx] + bt[idx];
        time = ct[idx];
        order.push_back(idx);
    }

  
  
    cout << "\n|";
    for(int i=0;i<n;i++) cout << "..P" << order[i]+1 << "..|";
    cout << "\n ";
 
    cout << "\n";

    cout << start[order[0]];
    for(int i=0;i<n;i++){
        int space = 7;
        cout << string(space - to_string(ct[order[i]]).length(), '  ') << ct[order[i]];
    }
    cout << "\n";

    // Table & averages
    double avgWT=0, avgTAT=0;
    cout << "\nProcess Arrival Burst Waiting Turnaround Completion\n";
    for(int i=0;i<n;i++){
        avgWT += wt[i];
        avgTAT += tat[i]; 
        cout << "P" << i+1 << "      " << at[i] << "        " << bt[i]
             << "        " << wt[i] << "        " << tat[i] << "        " << ct[i] << "\n";
    }


    
    cout << "\nAverage Waiting Time = " << avgWT/n;
    cout << "\nAverage Turnaround Time = " << avgTAT/n << "\n";

    return 0;
}
