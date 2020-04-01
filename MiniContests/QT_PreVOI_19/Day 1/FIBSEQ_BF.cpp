#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "FIBSEQ"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5, md = 1e9 + 7;

int n, q;
int a[N], s[N], f[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> q;
    f[1] = 1;
    FOR(i, 2, q) f[i] = (f[i - 1] + f[i - 2]) % md;
    int cnt = 0;
    REP(i, q) {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        //cerr << ch << x << y << '\n';
        if (ch == 'D') {
            cnt ++;
            cerr << cnt << '\n';
            FOR(i, x, y) { 
                a[i] ++;
                s[i] = (s[i - 1] + f[a[i]]) % md;
            }
            FOR(i, y + 1, n) {
                s[i] = (s[i - 1] + f[a[i]]) % md;
            }
            //FOR(i, 1, n) cerr << a[i] << ' '; cerr << '\n';
            //FOR(i, 1, n) cerr << s[i] << ' '; cerr << '\n';
        } else {
            int res = (s[y] - s[x - 1]) % md;
            if (res < 0) res += md;
            cout << res << '\n';
        }
    }
    // cerr << cnt << '\n';
}
