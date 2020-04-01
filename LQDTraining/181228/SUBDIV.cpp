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

#define task "SUBDIV"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, k, sumRem, cnt[N];
string s;
ll res;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> k;
    cnt[0] = 1;
    FOR(i, 1, n) {
        cin >> s;
        int l = s.size(), Exp = 1;
        FORD(i, l - 1, 0) {
            sumRem = (sumRem + (s[i] - '0') * Exp) % k;
            Exp = Exp * 10 % k;
        }
        res += cnt[sumRem];
        cnt[sumRem] ++;

    }
    cout << res;
}

