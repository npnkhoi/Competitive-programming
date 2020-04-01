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

const int N = 1e5 + 5;
const double oo = 1e9;
struct point{ int X, Y;};
bool cmpx(point a, point b) { return a.X < b.X;}
bool cmpy(point a, point b) { return a.Y < b.Y;}
double dist(point a , point b) {
    return sqrt((double)(a.X - b.X)*(a.X - b.X) + (double)(a.Y- b.Y)*(a.Y- b.Y));
}
point p[N], q[N];

double minDist(int l, int r) {
    if (l >= r) return oo;
    int mi = (l + r) / 2;
    double d = min(minDist(l, mi), minDist(mi+1, r));

    int m = 0;
    for (int i = l; i <= r; i++)
    if (abs(p[i].X - p[mi].X) <= d) q[++m] = p[i];
    sort(q+1, q+m+1, cmpy);

    for (int i = 1; i < m; i++)
    for (int j = i+1; j <= min(i+6, m); j++)
    d = min(d, dist(q[i], q[j]));
    return d;
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].X, &p[i].Y);
    sort(p+1, p+n+1, cmpx);
    printf("%.3lf", minDist(1, n));
    return 0;
}
/** Happy Coding ^^ */

