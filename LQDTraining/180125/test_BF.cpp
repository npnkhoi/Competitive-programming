#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "test"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

string s;
int n;

bool same(int i, int j, int d) {
    FOR(x, 0, d-1) if (s[i+x] != s[j+x]) return false;
    return true;
}
bool ok(int val) {
    REP(i, n)
    FOR(j, i + val, n - 1) if (i != j && same(i, j, val)) return true;
    return false;
}
int main() {
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d ", &n);
    getline(cin, s);

    FORD(i, n/2, 1) if (ok(i)) {
        printf("%d", i);
        return 0;
    }

    printf("0");
}
/// Expelliarmus !
