using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
const int N = 2e5 + 10;
int a[N], res[N];
ii b[N];
int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i].fi);
        b[i].se = i;
    }
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; i++) res[b[i].se] = a[n-i+1];
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
    return 0;
}
/** Happy Coding ^^ */
