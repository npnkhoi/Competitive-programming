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
const int N = 1000 + 5;
int a[N][N], m, n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool sign[N][N];
bool adj(int i, int j) {
    if (a[i][j] == 0) return 0;
    for (int z = 0; z < 4; z++) {
        int u = i + dx[z];
        int v = j + dy[z];
        if (a[u][v] == 1) return 1;
    }
    return 0;
}
void sub1() {
    int res = -1, resI, resJ, resR;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        memset(sign, 0, sizeof sign);
        bool stop = false;
        int r, cnt = 0;
        for (r = 0; !stop && i - r >= 1 && i + r <= m && j - r >= 1 && j + r <= n; r++) {
            for (int x = i - r; x <= i + r; x++) {
                int d = r - abs(i - x);
                if (d == 0) {
                    cnt += a[x][j];
                    if (adj(x, j)) stop = 1;
                } else {
                    cnt += a[x][j-d] + a[x][j+d];
                    if (adj(x, j-d) || adj(x, j+d)) stop = 1;
                }
            }
        }
        if (cnt > res) {
            res = cnt;
            resI = i;
            resJ = j;
            resR = r-1;
        }
    }
    printf("%d %d %d %d\n", res, resI, resJ, resR);
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &m, &n);
    char ch;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        scanf(" %c", &ch);
        a[i][j] = (ch == '*');
    }
    sub1();
    return 0;
}
/** Happy Coding ^^ */
