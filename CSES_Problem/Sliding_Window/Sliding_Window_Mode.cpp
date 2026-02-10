#include <bits/stdc++.h>
using namespace std;

// frequency map
unordered_map<int,int> freq;

// set keeps {-frequency, value} sorted
set<pair<int,int>> st;

// add element to window
void addValue(int x) {
    if (freq[x] > 0) {
        st.erase({-freq[x], x});
    }
    freq[x]++;
    st.insert({-freq[x], x});
}

// remove element from window
void removeValue(int x) {
    st.erase({-freq[x], x});
    freq[x]--;
    if (freq[x] > 0) {
        st.insert({-freq[x], x});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {

        // add new element
        addValue(v[i]);

        // remove old element if window exceeded
        if (i >= k) {
            removeValue(v[i - k]);
        }

        // window ready
        if (i >= k - 1) {
            ans.push_back(st.begin()->second);
        }
    }

    // print result
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
