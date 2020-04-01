#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "select"
typedef long long ll;
//typedef pair<int, int> ii;

const int N = 1e6 + 5;
int n, a[N];
int sum(int l, int r) {
    int res = 0;
    while (1) {
        res += a[l];
        if (l == r) break;
        if (l == n) l = 1;
        else l++;
    }
    return res;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        char ch;
        scanf(" %c", &ch);
        if (ch == '+') a[i] = 1;
        else a[i] = -1;
    }
    long long res = 0;
    FOR(l, 1, n) FOR(r, 1, n) {
        res += (sum(l, r) == 0);
        //if (sum(l, r) == 0) cerr << l << " " << r << "\n";
    }
    if (sum(1, n) == 0) res -= (n-1);
    printf("%d\n", res);
}
/// Expelliarmus !
