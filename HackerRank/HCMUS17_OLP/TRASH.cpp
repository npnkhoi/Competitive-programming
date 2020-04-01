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
const int N = 1e6 + 2;
ll a[N], t, res;
int n;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %lld", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i-1];
    }
    int i = 1;
    for (int j = 1; j <= n; j++) {
        while (a[j] - a[i-1] > t) i++;
        res += 1LL * (j - i + 1);
    }
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding ^^ */

