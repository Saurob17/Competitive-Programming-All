#include<bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        /* code */


        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (k % 2 == 0) {
            sort(s.begin(), s.end());
            cout << s;
        }
        else {
            vector<char>o, e;
            for (int i = 0;i < n;i++) {
                if (i % 2 == 0) {
                    o.push_back(s[i]);
                }
                else {
                    e.push_back(s[i]);
                }

            }
            sort(e.begin(), e.end());
            sort(o.begin(), o.end());
            int i = 0, j = 0;
            int od = 1;
            while (i <= e.size() && j < o.size())
            {
                /* code */
                if (od) {
                    cout << o[i];
                    i++;
                    od = 0;
                }
                else {
                    cout << e[j];
                    j++;
                    od = 1;
                }


            }

        }
        cout<<endl;

    }
}

/*
\newpage
\begin{multicols}{3}
% --- COLUMN 1 ---
\section*{Deque (dq)}
\begin{verbatim}
dq.push_back(x);    // O(1)
dq.push_front(x);   // O(1)
dq.pop_back();      // O(1)
dq.pop_front();     // O(1)
dq[i];              // O(1)
\end{verbatim}

\columnbreak
% --- COLUMN 2 ---
\section*{Queue (q)}
\begin{verbatim}
queue<int> q;
q.push(x);          // O(1)
q.pop();            // O(1)
q.front();          // O(1)
q.back();           // O(1)
q.empty();          // O(1)
q.size();           // O(1)
\end{verbatim}

\columnbreak
% --- COLUMN 3 ---
\section*{Priority Queue (pq)}
\begin{verbatim}
priority_queue<int> pq;
pq.push(x);         // O(log n)
pq.pop();           // O(log n)
pq.top();           // O(1)
pq.size();          // O(1)
pq.empty();         // O(1)
\end{verbatim}

\end{multicols}
*/