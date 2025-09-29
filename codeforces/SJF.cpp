#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    };

    //priority_queue<
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> BT(cmp);
    int Pro_num = 1, bt;
    for (int i = 0; i < n; i++)
    {

        cin >> bt;
        BT.push({bt, i + 1});
    }
    auto cmpo = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == a.second)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }

    int total_tat = 0,
         total_wt = 0;

    for (int i = 0; i < n; i++)
    {
        auto p = BT.top();
        BT.pop();
        int bt = p.first;
        int pro_id = p.second;
        int wt = total_tat;
        int tat = wt + bt;
        total_wt += wt;
        total_tat += tat;
        cout << "Process " << pro_id << ": Burst Time = " << bt << ", Waiting Time = " << wt << ", Turnaround Time = " << tat << "\n";
    }
    cout << "Average Waiting Time = " << (double)total_wt / n << "\n";
    cout << "Average Turnaround Time = " << (double)total_tat / n << "\n";
}