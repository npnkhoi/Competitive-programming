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

#define task "CARROT"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 7000 + 5, oo = 1e9 + 7;

int n;
lint s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    cin >> n;
    FOR(i, 1, n) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    int res = 0;
    REP(mask, (1 << (n - 1))) {
        vi pos = {0};
        REP(i, n - 1) if (mask >> i & 1) {
            pos.push_back(i + 1);
        }
        pos.push_back(n);
        int flag = 1;
        FOR(i, 2, pos.size() - 1) {
            if (s[pos[i]] - s[pos[i - 1]] < s[pos[i - 1]] - s[pos[i - 2]]) {
                flag = 0;
                break;
            }
        }
        if (flag) res = max(res, (int)pos.size() - 1);
    }
    cout << res;
}
