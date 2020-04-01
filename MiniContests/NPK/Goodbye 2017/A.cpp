#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "A"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

long long Rand(long long l, long long r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r-l+1);
}
long long val(long long x, long long y, long long half, long long res) {
    //printf("%lld %lld %lld %lld\n", x, y, half, res);
    if (half == 0) return res;
    if (x > half && y > half) return val(x - half, y - half, half / 2, res);
    if (x <= half && y <= half) return val(x, y, half / 2, res);
    if (x > half) return val(x - half, y, half / 2, res + half);
    return val(x, y - half, half / 2, res + half);
}
void makeTest() {
    ofstream inp(task".inp");
    int q = 1;
    inp << q << "\n";
    while (q--) {
        inp << "74 57\n";
        inp << Rand(1, 1e18) << " " << Rand(1, 1e18) << "\n";
    }

    inp.close();
}
int main() {
    srand(time(NULL));
    makeTest();
    freopen(task".inp",     "r", stdin);
    //freopen(task".out", "w", stdout);
    int q;
    scanf("%d", &q);
    while (q--) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        cout << x  << " " << y << "\n";
        printf("%lld\n", val(x, y, 1LL << 62, 1));
        cout << (((x-1) ^ (y-1))  + 1) << "\n";
        int verdict = val(x, y, 1LL << 62, 1) - (((x-1) ^ (y-1))  + 1);
        cout << verdict << "\n";
        if (verdict) {
            cout << "WRONG\n";
            return 0;
        }
    }

}
/// Expelliarmus !
