using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)

const int N = 1e6 + 5;

int f[N];
ull a, b;
int m, ck;
ull Exp(ull a, ull b, int m) {
    a %= m;
    if (b == 1) return a;
    else {
        int s = Exp(a, b/2, m);
        s = (s * s) % m;
        if (b%2) s = (s * a) % m;
        return s;
    }
}
void task1() {
    f[0] = 0; f[1] = 1;
    ck = 0;

    for (int i = 2; ; ++i) {
        f[i] = (f[i-1] + f[i-2]) % m;
        if (f[i] == 1 && f[i-1] == 0) {
            ck = i-1;
            break;
        }
    }
    printf("%d\n", f[Exp(a, b, ck)]);
}
void task2() {
    printf("%d\n", f[__gcd(a, b)%ck]);
}
int main() {
    freopen("FIB2.inp", "r", stdin);
    freopen("FIB2.out", "w", stdout);
    int tc;
    scanf("%d", &tc);

    while (tc--) {

        scanf("%lld %lld %d", &a, &b, &m);
        task1();
        //task2();
    }
    return 0;
}
/** Happy Coding ^^ */

