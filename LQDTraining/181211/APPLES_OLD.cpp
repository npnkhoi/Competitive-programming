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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

void init() {
    Exp[0] = 1;
    FOR(i, 1, 50) Exp[i] = Exp[i-1] * 2;
}

void buildEqn() {
    e[1][1] = 1;
    e[1][0] = firstWei;
    FOR(i, 2, n) {
        FOR(j, 1, n) e[i][j] = Exp[n - i];
        e[i][i - 1] -= Exp[n];
        e[i][i] += Exp[n];
    }
}

void solve() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	init();
    cin >> tc;
    REP(khue, tc) {
        cin >> n >> a[1];
        memset(e, 0, sizeof e);
        buildEqn();
    }
}
