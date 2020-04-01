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
const int N = 60;
ll C[N][N], k, x, res;
int ans[N], pos[N], cnt, m;
void init() {
    C[0][0] = 1;
    for (int i = 1; i <= 55; i ++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        if (C[i-1][j-1] == -1 || C[i-1][j] == -1) C[i][j] = -1;
        else {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if (C[i][j] > 1e15) C[i][j] = -1;
        }
    }
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    init();
    //cout << C[5][3] << endl;
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        res = 0;
        scanf("%lld %lld", &x, &k);
        cnt = m = 0;
        while (x) {
            ++ cnt;
            if (x&1) pos[++m] = cnt;
            x >>= 1;
        }
        for (int i = m; i >= 1; i--) k += C[pos[i]-1][i];
        k++;
        if (k > 1e15) res = -1;
        else {
            for (int i = m; i >= 1; i--) {
                ans[i] = -1;
                for (int j = 0; j <= 50; j++)
                if ((C[j][i] >= k || C[j][i] == -1) && (C[j-1][i] < k && C[j-1][i] != -1)) {
                    ans[i] = j;
                    k -= C[j-1][i];
                    break;
                }
                if (ans[i] == -1) {
                    res = -1;
                    break;
                }
            }
            if (res == 0) {
                for (int i = 1; i <= m; i++)
                res += (1LL << (ans[i] - 1));
                if (res > 1e15) res = -1;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
/** Happy Coding ^^ */

