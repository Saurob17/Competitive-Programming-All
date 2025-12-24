#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> q;
    int T;
    cin >> T;

    while (T--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (type == 2)
        {
            if (!q.empty())
                q.pop();
        }
        else
        {
            if (!q.empty())
                cout << q.front() << '\n';
            else
                cout << "Empty!\n";
        }
    }
    return 0;
}
