using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
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
const int N = 1e5 + 5;
int n, a[N], t[N], id[N];
ll L, ans[N];
bool cmp(int i, int j) {
    return a[i] < a[j] || (a[i] == a[j] && t[i] > t[j]);
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("WALKING.inp", "r", stdin);
    freopen("WALKING.out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d%lld", &n, &L);
    FOR(i, 1, n) {
        scanf("%d%d", &a[i], &t[i]);
        id[i] = i;
    }
    sort(id+1, id+n+1, cmp);
    ll maxArrive = 0;
    FOR(i, 1, n) {
        int u = id[i];
        maxArrive = max(maxArrive, a[u] + L * t[u]);
        ans[u] = maxArrive;
    }
    FOR(i, 1, n) printf("%lld\n", ans[i]);
    return 0;
}
/** Happy Coding :D */
