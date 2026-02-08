#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

// initialize DSU
void makeset(int n){
    parent.resize(n + 2);
    for(int i = 1; i <= n + 1; i++){
        parent[i] = i;
    }
}

// find next free slot (path compression)
int findPath(int v){
    if(parent[v] == v) return v;
    return parent[v] = findPath(parent[v]);
}

// park a car and link to next slot
int parkUnion(int want, int n){
    // find where the car will actually park
    int pos = findPath(want);

    // find next position (circular)
    int nextPos = pos + 1;
    if(nextPos == n + 1) nextPos = 1;

    // mark pos as occupied by linking it to next free slot
    parent[pos] = findPath(nextPos);

    return pos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    makeset(n);

    for(int i = 0; i < n; i++){
        int want;
        cin >> want;

        int parked = parkUnion(want, n);
        cout << parked << " ";
    }

    return 0;
}
