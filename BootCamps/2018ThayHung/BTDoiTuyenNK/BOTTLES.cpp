#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"

#define task "bottles"
#define inp cin
#define out cout

const int N = 1e6 + 5;
const int oo = 1e9 + 7;

int n, cnt, k, a[N], trace[N];
long long dp[N], s;
deque<int> dq;
bool mark[N];

ll val(int i) {
    return dp[i] + a[i+1];
}
void callTrace(int i) {
    if (i < k) return;
    cnt ++;
    mark[trace[i]+1] = 1;
    callTrace(trace[i]);
}
int main() {
    // ifstream inp("");
    // ofstream out("");
    inp >> n >> k;
    dq.push_back(0);

    FOR(i, 1, n) {
        inp >> a[i];
        s += a[i];
    }
    FOR(i, 1, n) {
        if (!dq.empty() && dq.front() < i - k) dq.pop_front();
        if (i >= k) {
            int x = dq.front();
            dp[i] = val(x);
            trace[i] = x;
        }
        while (!dq.empty() && val(dq.back()) >= val(i)) dq.pop_back();
        dq.push_back(i);
    }
    callTrace(n);

    out << s - dp[n];
    // out << n - cnt << " " << s - dp[n] << "\n";
    // FOR(i, 1, n) if (!mark[i]) out << i << " ";
}
/** Happy Coding :D */
