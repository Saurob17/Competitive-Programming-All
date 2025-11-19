#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }

        bool bc = true;

        vector<char> v;

        while (!dq.empty())
        {
            int front = dq.front();
            int back = dq.back();

            if (bc)
            {
                if (front >= back)
                {
                    v.push_back('L');
                    
                    dq.pop_back();
                    if(dq.empty()) break;
                    v.push_back('R');
                    dq.pop_front();
                }
                else
                {
                    v.push_back('R');dq.pop_front();
                     if(dq.empty()) break;
                    v.push_back('L');
                    
                    dq.pop_back();
                }
                bc = false;
            }
            else
            {
                if (front <= back)
                {
                    v.push_back('L');
                    dq.pop_front();
                     if(dq.empty()) break;
                    v.push_back('R');
                    dq.pop_back();
                }
                else
                {
                    v.push_back('R');
                    dq.pop_back();
                     if(dq.empty()) break;
                    v.push_back('L');
                    dq.pop_front();
                }
                bc = true;
            }
        }

                for (auto c : v)
        {
            cout << c;
        }
        cout << endl;
    }
}