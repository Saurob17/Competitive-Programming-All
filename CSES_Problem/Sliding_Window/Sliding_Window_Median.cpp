#include <bits/stdc++.h>
using namespace std;

multiset<int> low, up;
int k;

// low এবং up সেটের আকার নিয়ন্ত্রণ করার ফাংশন
void balance() {
    int low_target = (k + 1) / 2;
    
    // low সেটে উপাদান কম থাকলে up থেকে নিয়ে আসা
    while (low.size() < low_target && !up.empty()) {
        low.insert(*up.begin());
        up.erase(up.begin());
    }
    // low সেটে উপাদান বেশি থাকলে up তে পাঠিয়ে দেওয়া
    while (low.size() > low_target) {
        up.insert(*low.rbegin());
        low.erase(prev(low.end()));
    }
}

void addEle(int x) {
    if (low.empty() || x <= *low.rbegin()) {
        low.insert(x);
    } else {
        up.insert(x);
    }
    balance();
}

void remEle(int x) {
    // এখানে ভুল ছিল: iterator ব্যবহার করে ডিলিট করতে হবে
    auto it = low.find(x);
    if (it != low.end()) {
        low.erase(it);
    } else {
        it = up.find(x);
        if (it != up.end()) {
            up.erase(it);
        }
    }
    balance();
}

int main() {
    // Fast I/O নিশ্চিত করা
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        addEle(v[i]);
        
        // যখন উইন্ডো k সাইজের বেশি হয়ে যায়, তখন একদম পেছনেরটা বাদ দিতে হবে
        if (i >= k) {
            remEle(v[i - k]);
        }

        // যখন উইন্ডো পূর্ণ হয়, তখন মিডিয়ান প্রিন্ট করা
        if (i >= k - 1) {
            cout << *low.rbegin() << (i == n - 1 ? "" : " ");
        }
    }
    cout << "\n";
    return 0;
}