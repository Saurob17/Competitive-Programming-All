#include <bits/stdc++.h>
using namespace std;
//Time and Space complexity O(n)
int sum(int n, int i) {
    if (i < 1) return 0;
    int res = i + sum(n, i - 1);
    cout << res << " ";  // Now reachable
    return res;
}

int main() {
    sum(10, 10);  // Function call
    cout << endl;
}
