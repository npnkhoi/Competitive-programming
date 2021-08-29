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

#define task "SPC1"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 17;

int tc, n;

ll l, r, f[N][2], g[N];

int sumSeq(int n) {
    return n * (n + 1) / 2;
}

ll calc(ll num) {
    if (num == 0) return 0;

    string s;
    while (num) {
        s = (char)(num % 10 + '0') + s;
        num /= 10;
    }
    n = s.size();

    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);

    f[1][0] = sumSeq(s[0] - '0' - 1);
    g[1] = s[0] - '0';

    f[1][1] = s[0] - '0';

    //cerr << "calc " << s << '\n';
    FOR(i, 2, n) {
        f[i][0] = f[i - 1][0] * 10 + 45 * g[i - 1]
                + f[i - 1][1] * (s[i - 1] - '0') + sumSeq(s[i - 1] - '0' - 1);
        f[i][1] = f[i - 1][1] + s[i - 1] - '0';

        g[i] = g[i - 1] * 10 + s[i - 1] - '0';
        //cerr << i << ": " << f[i][0] << ' ' << f[i][1] << '\n';
    }
    return f[n][0] + f[n][1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	//cerr << calc(12) << '\n';
    cin >> tc;
    REP(NhiThun, tc) {
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }
}
