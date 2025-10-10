#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q;
    cin >> q;

    queue<pair<long long, long long>> pq;

    while (q--)
    {
        long long ty, c, x;
        cin >> ty;

        if (ty == 1)
        {
            cin >> c >> x;
            pq.push({c, x});
        }
        else
        {
            long long sum=0;
            int k;
            cin >> k;
            while (!pq.empty())
            {
                auto &it = pq.front();

                if(k>=it.first){
                    k-=it.first;
                   sum+=it.first*it.second;
                    pq.pop();
                }
                else{
                    sum+=k*it.second;
                    it.first-=k;
                    k=0;
                    break;
                }
            }
            cout<<sum<<endl;
        }
    }
}