using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    freopen("DIP.inp", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    int n = 33333;
    int m = 100000;
    printf("%d %d\n", 3*n, m);
    FOR(i, 1, n) printf("%d ", i);
    FOR(i, 1, n) printf("%d %d ", i, i + m);
    REP(i, m) printf("1 %d\n", n);
    return 0;
}
/** Happy Coding :D */
