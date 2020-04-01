#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "convention2"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, res, last, arr[N], dur[N], id[N];
priority_queue<int, vi, greater<int> > q;

bool cmp(int u, int v) {
    return arr[u] < arr[v];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) {
        cin >> arr[i] >> dur[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    last = 0;
    for (int i = 1; i <= n; ++ i) {
        q.push(id[i]);
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            //debug(u);
            res = max(res, last - arr[u]);
            last = max(last, arr[u]) + dur[u];
            while (i < n && arr[id[i + 1]] <= last) {
                ++ i;
                //cerr << "push " << i << "into queue\n";
                q.push(id[i]);
            }
        }
    }
    cout << res;
}
