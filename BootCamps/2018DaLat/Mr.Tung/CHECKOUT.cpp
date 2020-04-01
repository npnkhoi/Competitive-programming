using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;
typedef vector<int> vi;
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
//ifstream inp("CHECKOUT.inp");
//ofstream out("CHECKOUT.out");
int main() {
    freopen("CHECKOUT.inp", "r", stdin);
    freopen("CHECKOUT.out", "w", stdout);
    ld d, a1, a2, v0, t;
    //scanf("%lf%lf%lf%lf%lf", &d, &a, &b, &v0, &t);
    cin >> d >> a1 >> a2 >> v0 >> t;
    /*long double v = (-t + sqrt(t*t+d*2*(a+b)/(a*b))) / ((a+b)/(a*b));
    v = min(v, v0);
    cout << fixed << setprecision(12) << v/a + v/b + (d-v*v/(2*a) - v*v/(2*b)) / v;*/
    ld A = 0.5/a1 + 0.5/a2;
    ld B = t;
    ld C = -d;

    ld delta = B*B - 4*A*C;
    ld v = (-B + sqrt(delta)) / (2*A);
    //cerr << v << "\n";
    v = min(v, v0);
    //cerr << v << "\n";

    cout << fixed << setprecision(12) << v/a1 + v/a2 + (d - 0.5*v*v/a1 - 0.5*v*v/a2) / v;


    return 0;
}
/** Happy Coding :D */
