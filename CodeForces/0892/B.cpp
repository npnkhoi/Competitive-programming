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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e6 + 5;
int n, a[N];

int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x;
        scanf("%d", &x);
        -- a[max(1, i-x)];
        a[i] ++;
    }
    int tmp = 0, res = 0;
    FOR(i, 1, n) {
        tmp += a[i];
        if (tmp >= 0) res ++;
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
