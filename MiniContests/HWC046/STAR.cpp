using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)

const int N = 3e4 + 2;
ll sqr(ll a) {return a*a;}

ll x[N], y[N], u[N], v[N];
int main() {
    freopen("STAR.inp", "r", stdin);
    freopen("STAR.out", "w", stdout);
    int n;
    ll t, day = 1, res = 0;

    scanf("%d %lld", &n, &t);
    FOR(i, 1, n) {
        scanf("%lld%lld%lld%lld", &x[i], &y[i], &u[i], &v[i]);
        FOR(j, 1, i-1) {
            ll d;
            ll a = sqr(u[i] - u[j]) + sqr(v[i] - v[j]);
            ll b = 2 * ((x[i] - x[j])*(u[i] - u[j]) + (y[i] - y[j])*(v[i] - v[j]));
            ll c = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
            if (a == 0) {
                if (b < 0) d = 0;
                else d = t;
            } else {
                double tmp = -0.5 * b / a;
                if (tmp > t) d = t;
                else if (tmp < 0) d = 0;
                else d = int(floor(tmp + 0.5));
            }
            ll tmp = a*d*d + b*d + c;
            if (tmp > res) {
                res = tmp;
                day = d;
            }
        }
    }
    printf("%lld %dlld", day, res);
    return 0;
}
/** Happy Coding ^^ */

