#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
    }

    auto it = st.begin();

    while (!st.empty())
    {
        // move to next (skip one person)
        it++;
        if (it == st.end())
            it = st.begin();

        // print removed element
        cout << *it << " ";


        // erase and get next valid iterator
        it = st.erase(it);

        // যদি erase করার পর end হয় → আবার begin এ নিয়ে আসো
        if (it == st.end() && !st.empty())
            it = st.begin();
    }

}