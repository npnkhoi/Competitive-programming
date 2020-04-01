#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 1005;
double sqr(double x) {return x*x;}
int n;
double r, x[N], y[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d %lf", &n, &r);
    FOR(i, 1, n) {
        scanf("%lf", &x[i]);
        y[i] = r;
        FOR(j, 1, i-1) if (abs(x[i] - x[j]) <= 2*r) {
            y[i] = max(y[i], y[j] + sqrt(sqr(2*r) - sqr(x[i] - x[j])));
        }
        printf("%.10f ", y[i]);
    }
}
/// Expelliarmus !
