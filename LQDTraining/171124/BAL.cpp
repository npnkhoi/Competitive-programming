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
const int N = 1e6 + 5;
bool mark[N];
int n, val, res;
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &val);
        if (mark[val+1]) mark[val+1] = 0;
        else res ++;
        mark[val] = 1;
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding :D */
