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
int a[8];
int s;
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    REP(i, 6) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    REP(mask, 1<<6) if (__builtin_popcount(mask) == 3) {
        int tmp = 0;
        REP(j, 6) if ((mask & 1<<j) > 0) tmp += a[j];
        if (tmp*2 == s) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
/** Happy Coding :D */
