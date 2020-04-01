#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 1e5 + 5;
int tc, n, m;
char s[N];
bool mark[N];
int a[N];
vector<int> tmp[30];
int main() {
    //  freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d", &n);
        scanf("%s", s+1);
        m = 0;
        FOR(i, 1, n) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '0') a[++m] = i;
        }
        memset(mark, 0, sizeof mark);
        mark[0] = mark[m] = 1;
        long long res = a[m];

        FOR(t, 1, n) {
            int preMark = 0;
            FOR(i, 1, m) if (mark[i] && preMark == i-1) {
                preMark ++;
            } else {
                if (a[i]-t+1 <= 0) tmp[0].push_back(a[i]);
                else tmp[s[a[i]-t+1] - 'a' + 1].push_back(a[i]);

                if (mark[i]) {
                    FOR(j, 0, 26) {
                        if (j > 0) res = max(res, (long long) t * (long long) tmp[j].size());
                        REP(k, tmp[j].size()) a[++preMark] = tmp[j][k];
                        mark[preMark] = 1;
                        tmp[j].clear();
                    }
                }
            }
            //printf("t = %d\n", t);
            //FOR(i, 1, m) printf("%5d", a[i]); cerr << "\n";
            //FOR(i, 1, m) printf("%5d", mark[i]); cerr << '\n';
        }
        printf("%lld\n", res);
    }
}
