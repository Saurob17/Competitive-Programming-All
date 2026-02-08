#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int>& a){
    int n = a.size();
    vector<int> ps(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if(st.empty()) ps[i] = -1;
        else ps[i] = st.top();

        st.push(i);
    }
    return ps;
}

vector<int> nextSmaller(vector<int>& a){
    int n = a.size();
    vector<int> ns(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] > a[i])
            st.pop();

        if(st.empty()) ns[i] = n;
        else ns[i] = st.top();

        st.push(i);
    }
    return ns;
}

long long sumSubarrayMins(vector<int>& a){
    int n = a.size();
    auto ps = prevSmaller(a);
    auto ns = nextSmaller(a);

    long long ans = 0;

    for(int i=0;i<n;i++){
        long long left  = i - ps[i];
        long long right = ns[i] - i;

        ans += a[i] * left * right;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    cout << sumSubarrayMins(a) << endl;

    return 0;
}
