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

ull n, H;
ull f(ull L) {
    if (L <= H) return L * (L + 1) / 2;
    else {
        ull tmp = H * (H + 1) / 2 + H;
        ull x = (L - H - 1) / 2;
        ull y = (L - H) / 2;
        //cerr << x << " " << y << "\n";
        return tmp + x * (x+1) / 2 + y * (y+1) / 2 + H * (L - H - 1);
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%lld%lld", &n, &H);
    ull l, r, ans;
    l = 1;
    r = 2e9;
    ans = r;

    while (l <= r) {
        ull mid = (l + r) / 2;
        if (f(mid) >= n) ans = mid, r = mid - 1;
        else l = mid + 1;
        //cerr << l << "  " << r << "\n";
    }
    //cerr << f(1999999999) << "\n";
    printf("%lld", ans);
}

