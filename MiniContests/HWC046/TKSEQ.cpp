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
const ll oo = 1e15 + 5;
int n, k;
int a[N], d[N];
ll s[N];
int main() {
    freopen("TKSEQ.inp", "r", stdin);
    freopen("TKSEQ.out", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, k) {
        d[3*i+1] = 1;
        d[3*i+2] = -1;
        d[3*i+3] = 1;
    }
    FOR(i, 1, 3*k) s[i] = -oo;
    int num;
    FOR(i, 1, n) {
        scanf("%d", &num);
        FOD(j, min(i,3*k), 1) {
            s[j] = max(s[j], s[j-1] + 1LL * num * d[i]);
        }
    }
    printf("%lld", s[3*k]);
    return 0;
}
/** Happy Coding ^^ */

