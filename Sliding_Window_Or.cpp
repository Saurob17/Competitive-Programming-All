#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10000005;

// মেমোরি এবং স্পিড বাঁচাতে গ্লোবাল অ্যারে
int val_arr[MAXN];
int s1[MAXN], s1_or[MAXN];
int s2[MAXN], s2_or[MAXN];
int top1 = -1, top2 = -1;

// স্ট্যাক ১-এ পুশ করার ফাংশন
void push(int x) {
    top1++;
    s1[top1] = x;
    if (top1 == 0) s1_or[top1] = x;
    else s1_or[top1] = s1_or[top1 - 1] | x;
}

// স্ট্যাক ২-এর মাধ্যমে পপ এবং OR ক্যালকুলেট করার ফাংশন
void pop_and_maintain() {
    if (top2 == -1) {
        while (top1 >= 0) {
            int x = s1[top1];
            top1--;
            top2++;
            s2[top2] = x;
            if (top2 == 0) s2_or[top2] = x;
            else s2_or[top2] = s2_or[top2 - 1] | x;
        }
    }
    if (top2 >= 0) top2--;
}

int get_window_or() {
    int res = 0;
    if (top1 >= 0) res |= s1_or[top1];
    if (top2 >= 0) res |= s2_or[top2];
    return res;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    // জেনারেটর লুপ
    val_arr[0] = (int)x;
    for (int i = 1; i < n; i++) {
        val_arr[i] = (int)(((long long)val_arr[i - 1] * a + b) % c);
    }

    unsigned long long final_xor_sum = 0;

    for (int i = 0; i < n; i++) {
        push(val_arr[i]);

        if (i >= k) {
            pop_and_maintain();
        }

        if (i >= k - 1) {
            final_xor_sum ^= get_window_or();
        }
    }

    cout << final_xor_sum << "\n";

    return 0;
}