#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[20], bt[20], wt[20], tat[20], ct[20], start[20], done[20]={0};

    cout << "Enter Arrival and Burst Time:\n";
    for(int i=0;i<n;i++)
        cin >> at[i] >> bt[i];

    int completed = 0, time = 0;
    while(completed < n){
        int idx = -1, minBT = INT_MAX;
        for(int i=0;i<n;i++)
            if(!done[i] && at[i]<=time && bt[i]<minBT)
                idx=i, minBT=bt[i];

        if(idx==-1){ time++; continue; }

        start[idx] = time;
        wt[idx] = time - at[idx];
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = wt[idx] + bt[idx];
        done[idx] = 1;
        completed++;
    }

    cout << "\nGantt Chart:\n";

    // Top border
    cout << " ";
    for(int i=0;i<n;i++) cout << "--------";
    cout << "\n|";

    // Process boxes
    for(int i=0;i<n;i++) cout << "  P" << i+1 << "   |";
    cout << "\n ";

    // Bottom border
    for(int i=0;i<n;i++) cout << "--------";
    cout << "\n";

    // Timeline (simple)
    for(int i=0;i<n;i++) cout << start[i] << "\t";
    cout << ct[n-1] << "\n";

    // -------------------- Table --------------------
    double avgWT=0, avgTAT=0;
    cout << "\nProcess Arrival Burst Waiting Turnaround Completion\n";
    for(int i=0;i<n;i++){
        avgWT += wt[i]; avgTAT += tat[i];
        cout << "P" << i+1 << "     " << at[i] << "       " << bt[i]
             << "       " << wt[i] << "       " << tat[i] << "       " << ct[i] << "\n";
    }
    cout << "\nAverage Waiting Time = " << avgWT/n;
    cout << "\nAverage Turnaround Time = " << avgTAT/n << "\n";
}
