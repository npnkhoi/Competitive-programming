using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

int fn(int x) {
    return ((1<<x) - 1) * (1<< (x-1));
}
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    scanf("%d", &n);
    int res = 1;
    for (int i = 1; fn(i) <= n; i++) {
        if (n % fn(i) == 0) res = max(res, fn(i));
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding :D */
