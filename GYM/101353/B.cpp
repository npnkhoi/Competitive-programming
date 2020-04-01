using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int tc;
    double a, p, b;
    scanf("%d", &tc);
    FOR(i, 1, tc) {
        scanf("%lf%lf%lf", &a, &p, &b);
        //cin >> a >> p >> b;
        //cerr << a << " " << b << " " << p << "\n";
        //cerr << log(b/a)/log(p/100+1) << "\n";
        //cout << "Case " << i << ": ";
        //if (b <= a) cout << "0\n";
        //else cout << (ll)ceil(log(b/a)/log(p/100+1)) << "\n";
        if (a >= b) printf("Case %d: 0\n", i);
        else printf("Case %d: %lld\n", i, (ll)ceil(log(b/a)/log(p/100+1)));
    }
    return 0;
}
/** Happy Coding ^^ */

