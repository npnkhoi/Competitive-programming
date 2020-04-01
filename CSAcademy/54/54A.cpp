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
const int N = 102;
int n, k, s, a[N];
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    s = 0;
    for (int i = 1; i <= k; i++) s += a[i];
    cout << (s+99) / 100;
    return 0;
}
/** Happy Coding ^^ */

