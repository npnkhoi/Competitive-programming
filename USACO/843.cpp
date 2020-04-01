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

#define task "mixmilk"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

int c[4], m[4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    FOR(i, 1, 3) cin >> c[i] >> m[i];
    int cur = 1, nxt = 2;
    FOR(i, 1, 100) {
        if (m[cur] + m[nxt] <= c[nxt]) {
            m[nxt] += m[cur];
            m[cur] = 0;
        }
        else {
            m[cur] -= c[nxt] - m[nxt];
            m[nxt] = c[nxt];
        }
        cur = nxt;
        nxt = (nxt == 3 ? 1 : nxt + 1);
    }
    cout << m[1] << '\n' << m[2] << '\n' << m[3];
}

