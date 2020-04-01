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
const int N = 2e5 + 5;
stack<int> st;
ii a[N];
vector<int> v;
int n, q, x;
int main() {
    freopen("COLLIDER.inp", "r", stdin);
    freopen("COLLIDER.out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d%d", &a[i].fi, &a[i].se);
        a[i].se = -a[i].se;
    }
    sort(a+1, a+n+1);
    FORD(i, n, 1) {
        if (a[i].se == 1)
            st.push(a[i].fi);
        else if (!st.empty()) {
            int tmp = st.top(); st.pop();
            v.push_back(tmp - a[i].fi);
        }
    }
    sort(v.begin(), v.end());
    //REP(i, v.size()) cerr << v[i] << " "; cerr << endl;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        x *= 2;
        int res;
        if (v.empty() || x < v[0]) res = 0;
        else res = upper_bound(v.begin(), v.end(), x) - v.begin();

        printf("%d\n", n - 2*res);
    }
    return 0;
}
/** Happy Coding ^^ */

