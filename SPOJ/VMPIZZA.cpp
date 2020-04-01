using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e5 + 5;
int n, B, t[N], a[N], b[N];
ll dp[N], sumT, sumA, _min;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d%d", &n, &B);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &t[i], &a[i], &b[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {

    }
    return 0;
}
/** Happy Coding ^^ */

