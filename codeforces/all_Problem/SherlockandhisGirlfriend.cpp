#include <bits/stdc++.h>
using namespace std;

/*
 diff(n) ফাংশন:
 1..n পর্যন্ত প্রতিটা সংখ্যাকে একটি label দেয়
 label দেওয়া হয় prime অনুযায়ী (sieve style)
*/
vector<int> diff(int n)
{
    n+=1;
    vector<int> v(n + 1);

    // initial value
    for (int i = 1; i <= n; i++)
        v[i] = i;

    // sieve style traversal
    for (int i = 2; i <= n; i++)
    {
        // i যদি prime হয়
        if (v[i] == i)
        {
            int k = 1;
            // i এর multiples
            for (int j = i; j <= n; j += i)
            {
                if (v[j] == j)
                {
                    v[j] = k;
                  if(k<2)k++;
                }
            }
        }
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v = diff(n);

    vector<int> ans;
    set<int> st;

    for (int i = 2; i <= n+1; i++)
    {
        ans.push_back(v[i]);
        st.insert(v[i]);
    }

    // number of distinct labels
    cout << st.size() << "\n";

    // print labels
    for (int x : ans)
        cout << x << " ";

    cout << "\n";
    return 0;
}
