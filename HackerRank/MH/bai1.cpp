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
int n, k, cnt[N][30];
char s[N];
ll res;
vector<int> pre[30];
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &k);
    scanf("%s", s+1);
    for (int i = 1; i <= k; i++) {
        char ch;
        scanf(" %c", &ch); int u = ch - 'a';
        scanf(" %c", &ch); int v = ch - 'a';
        pre[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        int v = s[i] - 'a';
        REP(j, pre[v].size()) {
            int u = pre[v][j];
            res += cnt[i-1][u];
        }
        for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i-1][j];
        cnt[i][s[i] - 'a'] ++;

    }
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding ^^ */

