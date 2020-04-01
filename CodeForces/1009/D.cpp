#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "D"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 2000 + 5;
int n, m;
int isPrime[N];
vi prime;
vector<ii> ans;
void sub1() {
    FOR(i, 1, n) FOR(j, i+1, n) {
        if (__gcd(i, j) == 1) {
            ans.pb(mp(i, j));
        }
    }
    if ((int) ans.size() >= m) {
        cout << "Possible\n";
        REP(i, m) cout << ans[i].fi << " " << ans[i].se << "\n";
    } else cout << "Impossible\n";
}
void sieve() { // remember to call this beneath "int main()"
    memset(isPrime, -1, sizeof isPrime);
    prime.pb(1);
    for (int i = 2; i < N; i++) if (isPrime[i] == -1){
        prime.push_back(i);
        //res += 1000 - 1000 / i;
        //printf("%d\n", i);
        for (long long j = 1LL*i*i; j < N; j+=i) isPrime[j] = 0;
    }
}
void sub2() {
    sieve();
    cout << "Possible\n";
    for (int i = 0; i <= (int) prime.size() && m > 0; i ++) {
        int u = prime[i];
        cerr << u << "\n";
        FOR(v, u + 1, n) if (u == 1 || v % u != 0) {
            m --;
            cout << u << " " << v << "\n";
            if (m == 0) break;
        }
    }
    cerr << m << "\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> m;
    if (m < n-1) {
        cout << "Impossible\n";
        return 0;
    }
    if (n <= 2000) sub1(); 
    else sub2();
}

