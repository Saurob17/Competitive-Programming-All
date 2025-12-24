/* unordered_map<int, string> um;

 for (auto &p : um) {
        cout << p.first << " -> " << p.second << endl;
    }

        m.erase(2);

        auto it = m.find(3); // Find key 3
if (it != m.end()) {
    m.erase(it); // Remove key 3
}


 unordered_set<int> us;  // Unordered set

    us.insert(5); // Won't be inserted (duplicate)

    for (int x : us) {
        cout << x << " ";
    }

    //mySet.erase(10);  // Removes the element 10 from the set

*/
// sive
/*
const int n = 1e6;
int main() {
  vector<int> v(n, 1);
  v[0] = v[1] = 0;
  for (int i = 2; i < n; i++) {
    if (v[i]) {
      for (int j = i * 2; j <= n; j += i) {
        v[j] = 0;
      }
    }
  }*/

// divisor

/*
vector<int> getDivisors(int n) {
  vector<int> divisors;
  for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
          divisors.push_back(i);  // Store divisor
          if (i != n / i) {
              divisors.push_back(n / i); // Store paired divisor
          }
      }
  }
  sort(divisors.begin(), divisors.end()); // Optional sorting
  return divisors;
}
*/

// nth root
/*

double nthRoot(double x, int n) {
  double low = 0, high = x, mid;
  double eps = 1e-7;  // Precision

  while (high - low > eps) {
      mid = (low + high) / 2.0;
      if (pow(mid, n) < x)
          low = mid;
      else
          high = mid;
  }
  return low;
}
//cout << fixed << setprecision(6) << nthRoot(x, n) << endl;
*/

// Binary Exponentiation Using Bitwise Method
/*

long long binExpo(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) { // If the least significant bit of b is 1
            res = (res * a) % mod;
        }
        a = (a * a) % mod;  // Square a
        b >>= 1; // Right shift b (divide by 2)
    }
    return res;
}

     cout << binExpo(a, b, mod) << endl;
*/

// mode
/*

int modFromString(string num, int n) {
    int res = 0;
    for (char digit : num) {
        res = (res * 10 + (digit - '0')) % n;  // Compute modulo step by step
    }
    return res;
}

// cout << modFromString(num, n) << endl;
*/

// binari search
/*

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoids overflow

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;  // Not found
}

    int result = binarySearch(arr, target);
    if (result != -1) cout << "Found at index " << result << endl;
    else cout << "Not found" << endl;
*/

// prime bruthforch
/*
/ Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to print all primes in the range [L, R]
void printPrimesInRange(int L, int R) {
    for (int i = L; i <= R; i++) {
        if (isPrime(i)) cout << i << " ";
    }
    cout << endl;
}

*/

/*#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, int> F_to_X; // Stores {F(X): X}
unordered_map<int, long long> dp; // Memoization of F(X)

// Function to compute F(X) recursively
long long computeF(int X) {
    if (X == 1) return 1;
    if (dp.count(X)) return dp[X];

    long long result;
    if (X % 2 == 0)
        result = computeF(X / 2) * computeF(X / 2) + 1;
    else
        result = computeF(X / 2) * computeF(X / 2 + 1) + 2;

    dp[X] = result;
    return result;
}


void precompute() {
    for (int i = 1; i <= 100000; i++) {
        long long F_val = computeF(i);
        if (F_val > 1e9) break; // Stop when F(X) exceeds 10^9
        F_to_X[F_val] = i; // Ensure proper mapping
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // Generate all F(X) values

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long FX;
        cin >> FX;
        cout << "Case " << i << ": " << F_to_X[FX] << "\n";
    }

    return 0;
}
*/

/*#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100001; // Increased to 100001
const int LOG = 20;

int log1[MAX_N];
int sprtt[MAX_N][LOG];

void logcomute(int n) {
    log1[1] = 0;
    for (int i = 2; i <= n; i++) {
        log1[i] = log1[i / 2] + 1;
    }
}

void sprt(int n, vector<int> &a) {
    for (int i = 0; i < n; i++) {
        sprtt[i][0] = a[i];
    }
    for (int j = 1; j <= log1[n]; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sprtt[i][j] = min(sprtt[i][j - 1], sprtt[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n); // Changed from int a[n] to vector<int>

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    logcomute(n);
    sprt(n, a);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

      //  l--; r--; // Converting 1-based index to 0-based

        int j = log1[r - l + 1];
        cout << min(sprtt[l][j], sprtt[r - (1 << j) + 1][j]) << endl;
    }
}*/
// string.erase(start_pos, length);
// string.erase(start_pos);
// string.insert(position, substring);
// iterator lower_bound(iterator start, iterator end, value);
//  auto it = lower_bound(arr.begin(), arr.end(), 5);
/*
 // Output the value
    if (it != arr.end()) {
        cout << "Lower Bound: " << *it << endl;  // Output: 5
    } else {
        cout << "No such element found." << endl;
    }*/
// iterator upper_bound(iterator start, iterator end, value);
// auto it = upper_bound(arr.begin(), arr.end(), 5);

/*Arithmetic Series (e.g., 1, 2, 3, 4, ...)
Geometric Series (e.g., 1, 2, 4, 8, ...)
Fibonacci Series (e.g., 0, 1, 1, 2, 3, 5, ...)
Other types like quadratic or polynomial series.
For example:
Arithmetic Series:

Nth term (Tₙ): a + (n-1) * d
Sum of first n terms (Sₙ): n/2 * (2a + (n-1) * d) where a is the first term and d is the common difference.
Geometric Series:

Nth term (Tₙ): a * r^(n-1) where a is the first term and r is the common ratio.
Sum of first n terms (Sₙ): a * (1 - r^n) / (1 - r) for r != 1.
*/

/*
vector<int> computeLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);  // Initialize LPS array with zeros
    int len = 0;  // Length of the previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Move back in the LPS array
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

*/
/*#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long binExpo(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        { // If the least significant bit of b is 1
            res = (res * a) % mod;
        }
        a = (a * a) % mod; // Square a
        b >>= 1;           // Right shift b (divide by 2)
    }
    return res;
}

int main()
{
    long long n, b, p1;
    cin >> n >> b >> p1;
    long long v, s, r, bn = 0, tr, t = 0,p=0;
    if (n < 2)
    {
        cout << 0 << " " << 0;
        return 0;
    }

    while (1)
    {
        if (n < 2)
            break;

        for (int i = 0; i < 32; i++)
        {
            p = binExpo(2, i, mod);
            if (p > n)
                break;
            tr = p;
        }

        s =tr;

        n = n -s+(s/2);
         cout<<s<<" "<<n<<endl;
        bn += (p / 2) * (b + 1);

          t +=( p / 2)*p1;

    }
    cout << bn << " " << t;
}*/
// int num = stoi(s); 
//string s = to_string(num);

#include <bits/stdc++.h>
using namespace std;
int main()
{
   
}
