using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
int Rand(int l, int r) {
    return l + rand() % (r-l+1);
}
int main() {
    //freopen("", "r", stdin);
    freopen("MECUNG.inp", "w", stdout);
    int n = (int) 1e5;
    int m = (int) 2e5;
    printf("%d %d\n", n, m);
    FOR(i, 1, m) {
        int u = Rand(2, n);
        int v = Rand(1, u-1);
        int c = Rand(1, (int) 1e9);
        printf("%d %d %d\n", u, v, c);
    }

    return 0;
}
/** Happy Coding ^^ */
