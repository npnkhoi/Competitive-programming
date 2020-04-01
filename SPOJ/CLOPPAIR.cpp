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
struct P {
    int X, Y;
    operator < (const P &a) {
        if (X != a.X) return X < a.X;
        else return Y < a.Y;
    }
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &p[i].X, &p[i].Y);
    sort(p, p+n);
    d = oo;
    for (int i = 1; i < n; i++) {

    }
    return 0;
}
/** Happy Coding ^^ */

