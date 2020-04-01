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
const int N = 5e5 + 5;
int a[N];

int main() {
    freopen("S_INDEX.inp", "r", stdin);
    freopen("S_INDEX.out", "w", stdout);
    int n;
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    if (a[1] == 0) printf("0");
    else {
        FORD(i, n, 1) if (a[i] >= i) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
/** Happy Coding :D */
