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
#define _USE_MATH_DEFINES
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const double PI = acos(-1);
double x, y, angle, shAngle, shDist;
int tc, m;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d", &m);
        angle = 90; x = y = 0;
        while (m --) {
            scanf("%lf%lf", &shAngle, &shDist);
            angle += shAngle;
            y += shDist * sin(angle * PI / 180.0);
            x += shDist * cos(angle * PI / 180.0);
        }
        printf("%.7f %.7f\n", x, y);
    }
}

