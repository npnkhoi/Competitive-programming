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

const int N = 5e5 + 5;

int n, s;
pair<ll, int> a[N];
deque<int> q;

bool cmp(ii u, ii v) {
    if (u.fi != v.fi) return u.fi > v.fi;
    else return u.se < v.se;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> s;
    FOR(i, 1, n) {
        cin >> a[i].fi;
        a[i].fi += a[i-1].fi;
        a[i].se = i;
    }
    sort(a, a + n + 1, cmp);
    int len = 0, pos;
    q.push_back(0);
    FOR(i, 1, n) {
        cerr << a[i].fi << ' ' << a[i].se << ' ';
        while (!q.empty() && a[q.back()].se >= a[i].se) q.pop_back();
        while (!q.empty() && a[i].fi - a[q.front()].fi > s) q.pop_front();
        if (!q.empty()) {
            cerr << a[q.front()].se;
            if (a[i].se - a[q.front()].se > len) {
                len = a[i].se - a[q.front()].se;
                pos = i;
            } else if (a[i].se - a[q.front()].se == len && a[i].se < pos) {
                pos = a[i].se;
            }
        }
        cerr << '\n';
        q.push_back(i);
    }
    cout << len << ' ' << pos - len + 1;
}

