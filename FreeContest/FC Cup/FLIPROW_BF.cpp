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

#define task "FLIPROW"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 25;

int n, m, a[N][N], b[N];
vi ans;

bool check(int col) {
    FOR(i, 1, n) b[i] = a[i][col];
    sort(b + 1, b + n + 1);
    FOR(i, 1, n - 1) {
        if (b[i] == b[i + 1]) {
            return false;
        }
    }
    return true;
}

bool getBit(int x, int i) {
    return x & (1 << i);
}

void rev(int row) {
    FOR(j, 1, m/2) swap(a[row][j], a[row][m-j+1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    REP(mask, (1 << (n-1))) {
        ans.clear();
        FOR(i, 1, n-1) if (getBit(mask, i-1)) {
            rev(i);
            ans.push_back(i);
        }
        bool flag = 1;
        FOR(j, 1, m) {
            if (!check(j)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n" << ans.size() << '\n';
            REP(i, ans.size()) cout << ans[i] << ' ';
            exit(0);
        }
        FOR(i, 1, n-1) if (getBit(mask, i-1)) {
            rev(i);
        }
    }
    cout << "No";
}
