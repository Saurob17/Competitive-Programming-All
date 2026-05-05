#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
long long bit[N];
int n;


// add value at index i
void update(int i, long long val) {
    for (; i <= n; i += i & -i) {
        bit[i] += val;
    }
}


// prefix sum from 1 to i
long long query(int i) {
    long long sum = 0;
    for (; i > 0; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}

// range sum l to r
long long rangeQuery(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = 10;

    update(1, 5);
    update(3, 2);
    update(5, 7);

    cout << query(5) << "\n";          // prefix sum
    cout << rangeQuery(2, 5) << "\n";  // range sum

    return 0;
}