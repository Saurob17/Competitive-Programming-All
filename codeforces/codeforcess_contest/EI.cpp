#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (k > (n * n)   || k==((n*n)-1))
        {
            cout << "NO"<<endl;
            continue;
        }


        cout << "YES\n";
        vector<string> grid(n);
int f=0;
        int col = 0;
        int cnt = 0;
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0; j < n ; j++)
            {
                if (cnt < k)
                {
                    grid[i] += 'U';
                    cnt++;
                    col = i;

                }
                else if(col==i && i==n-1  && f==0)
                {
                    grid[i] += 'R';
                    f=1;
                }
                 else if(col==i && i==n-1  && f==1)
                {
                    grid[i] += 'L';
                    f=1;
                }
                else if (col == i && i == 0)
                {
                    grid[i] += 'D';
                }
                else if (col == i)
                {
                    grid[i] += 'D';
                }
                else if (j == 0)
                {
                    grid[i] += 'R';
                }
                else
                {
                    grid[i] += 'L';
                }
            }
        }

        for (auto &row : grid)
            cout << row << endl;
    }
}
