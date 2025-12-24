#include <bits/stdc++.h>
using namespace std;

const int MAXP = 1000000;
vector<bool> isPrime(MAXP + 1, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXP; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAXP; j += i)
                isPrime[j] = false;
        }
    }
}

deque<long long> allDivisors(long long n)
{
    deque<long long> d;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();   // 🔴 MUST

    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++)
    {
        long long N;
        cin >> N;

        deque<long long> dq = allDivisors(N);
        deque<long long> ans;

        ans.push_back(dq.front());
        dq.pop_front();

        bool ok = true;
        int rotateLimit = dq.size() * dq.size();

        while (!dq.empty() && rotateLimit--)
        {
            long long last = ans.back();
            long long cur = dq.front();
            dq.pop_front();

            long long mx = max(last, cur);
            long long mn = min(last, cur);

            if (mx % mn == 0 && mx / mn <= MAXP && isPrime[mx / mn])
            {
                ans.push_back(cur);
            }
            else
            {
                dq.push_back(cur); // rotate
            }
        }

        cout << "Case " << cs << ":\n";
        if (!dq.empty())
        {
            cout << "impossible\n";
        }
        else
        {
            for (auto x : ans)
                cout << x << " ";
            cout << "\n";
        }
    }
}
