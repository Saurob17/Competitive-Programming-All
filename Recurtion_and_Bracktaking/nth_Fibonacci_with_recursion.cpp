#include<bits/stdc++.h>
using namespace std;
int  fib(int n){
	if(n<2)return n;
	int res=fib(n-1)+fib(n-2);

	return res;
}
int  main(){
	int n;

	cin >> n;
	cout << "Fibonacci number is " << fib(n) << endl;
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         long long total = 0;
//         for (int i = 0; i + 1 < n; i++)
//             total += abs(a[i] - a[i + 1]);

//         long long ans = total; // case: remove nothing

//         for (int i = 1; i + 1 < n; i++)
//         {
//             long long cur = total
//                 - abs(a[i] - a[i - 1])
//                 - abs(a[i] - a[i + 1])
//                 + abs(a[i - 1] - a[i + 1]);

//             ans = min(ans, cur);
//         }

//         // remove first
//         ans = min(ans, total - abs(a[0] - a[1]));

//         // remove last
//         ans = min(ans, total - abs(a[n - 2] - a[n - 1]));

//         cout << ans << "\n";
//     }
// }
