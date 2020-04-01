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
const int N = 1e6 + 5;
const int k = 1e6 + 2;
char s[N];
ii pos[2*N];
int cnt, res;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int tc = 0;
    while (scanf("%s", s+1) != EOF) {
        tc ++;
        int n = strlen(s+1);
        cnt = 0; res = 0; pos[k] = mp(n+1, tc);
        FOD(i, n, 1) {
            if (s[i] == 'A') cnt ++;
            else cnt --;
            if (pos[k + cnt - 1].se == tc) res = max(res, pos[k + cnt - 1].fi - i);
            if (pos[k + cnt + 1].se == tc) res = max(res, pos[k + cnt + 1].fi - i);
            if (pos[k + cnt].se == tc) res = max(res, pos[k + cnt].fi - i);
            if (pos[k + cnt].se < tc) pos[k + cnt] = mp(i, tc);
        }
        printf("%d\n", res);
    }

    return 0;
}
/** Happy Coding ^^ */

