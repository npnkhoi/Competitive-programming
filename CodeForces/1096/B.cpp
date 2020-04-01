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

ll comb(int n) {
    return (ll)n * (n + 1) / 2;
}

int n;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> s;
    int l = -1, r = -1;
    REP(i, n) if (s[i] != s[0]) {
        l = i;
        break;
    }
    FORD(i, n-1, 0) if (s[i] != s[n-1]) {
        r = i;
        break;
    }
    if (s[0] == s[n-1]) {
        cout << (ll) (n - 1 - r + 1) * (l - 0 + 1) % 998244353;
    } else {
        cout << (l - 0 + 1) + (n - 1 - r + 1) - 1;
    }
}
