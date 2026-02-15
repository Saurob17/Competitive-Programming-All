#include <iostream>
#include <vector>

using namespace std;

int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<int> res(N + 1);

    for (int i = N; i >= 1; i--) {
        if (A[i] == i) {
            res[i] = i; 
        } else {
            res[i] = res[A[i]]; 
        }
    }

   
    for (int i = 1; i <= N; i++) {
        cout << res[i] <<" ";
    }
    cout << endl;

    
}