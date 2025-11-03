#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;

    s.insert(12);
    s.insert(5);
    s.insert(8);
    s.insert(1);
    s.insert(20);
    s.insert(5); // duplicate ignored

    for (auto &it : s)
    {
        cout << it << " ";
    }
    cout << "\n";
    // search key and return iterator to that key
    if (s.find(8) == end(s))
    {
        cout << "Not Found\n";
    }
    else
    {
        cout << "Found 8\n";
    }

    // delete specific key
    s.erase(5);

    for (auto &it : s)
    {
        cout << it << " ";
    }
    cout << "\n";


    //unordered set
    unordered_set<int> us;

    us.insert(12);
    us.insert(5);
    us.insert(8);
    us.insert(1);
    us.insert(20);
    us.insert(5); // duplicate ignored

    for (auto &it : us)
    {
        cout << it << " ";
    }

    cout << "\n";
    // search key and return iterator to that key
    if (us.find(8) == end(us)){
        cout << "Not Found\n";
    }
    else{
        cout << "Found 8\n";
    }
    auto it = us.find(8);
    cout<<*it<<"\n";


}