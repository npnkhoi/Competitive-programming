using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 5e4 + 5;
int a[N], b[N], pos[N], n;
void solve(int l, int r, int u, int v) {
    if (l > r) return;
    int x = pos[a[l]] - u;
    solve(l+1, l+x, u, u+x-1);
    solve(l+x+1, r, u+x+1, v);
    printf("%d ", a[l]);
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) {
        scanf("%d", &b[i]);
        pos[b[i]] = i;
    }
    solve(1, n, 1, n);

    return 0;
}
/** Happy Coding ^^ */
