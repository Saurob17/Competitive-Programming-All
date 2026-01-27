#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n + 2); // 1-based indexing
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> L(n + 2), R(n + 2);
    stack<int> st;

    // Step 1: Nearest smaller to left
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        L[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    // Step 2: Nearest smaller to right
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        R[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    // Step 3: answer[x] = max strength for window size x
    vector<long long> answer(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        int len = R[i] - L[i] - 1;
        answer[len] = max(answer[len], a[i]);
    }

    // Step 4: propagate max to smaller lengths
    for (int i = n - 1; i >= 1; i--) {
        answer[i] = max(answer[i], answer[i + 1]);
    }

    // Step 5: print answers
    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}
