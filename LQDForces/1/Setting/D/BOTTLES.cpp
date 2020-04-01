#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int oo = 1e9 + 7;

int n, cnt, k, a[N], trace[N];
long long dp[N], s;
deque<int> dq;
bool mark[N];

ll val(int i) {
    return dp[i] + a[i+1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    dq.push_back(0);
    FOR(i, 1, n) {
        cin >> a[i];
        s += a[i];
    }
    // cerr << "ok\n";
    FOR(i, 1, n) {
        // if (i % 10000 == 0) cerr << dq.size() << "\n";
        if (!dq.empty() && dq.front() < i - k) dq.pop_front();
        if (i >= k) {
            int x = dq.front();
            dp[i] = val(x);
            trace[i] = x;
        }
        while (!dq.empty() && val(dq.back()) >= val(i)) dq.pop_back();
        dq.push_back(i);
    }
    // cerr << "done\n";
    // callTrace(n);

    cout << s - dp[n];
    // out << n - cnt << " " << s - dp[n] << "\n";
    // FOR(i, 1, n) if (!mark[i]) out << i << " ";
}
/** Happy Coding :D */
