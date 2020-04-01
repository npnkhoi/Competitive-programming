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
const int N = 1e5 + 2;
const int maxN = 1e6 + 2;
int m, n, q, h[N], l[N], r[N];
bool era[maxN + 2];
void sieve() {
    era[0] = era[1] = 1;
    for (int i = 2; i <= maxN; i++) if (era[i] == 0)
    for (ll j = 1LL * i * i; j <= maxN; j += 1LL * i) era[j] = 1;
}
void build(int IT[], int a[], int p, int l, int r) {
    if (l == r) IT[p] = a[l];
    else {
        int mid = (l + r) / 2;
        build(IT, a, 2*p, l, mid);
        build(IT, a, 2*p+1, mid+1, r);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
int rmq(int IT[], int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r) return -1;
    else if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l + r) / 2;
        int res1 = rmq(IT, 2*p, l, mid, L, R);
        int res2 = rmq(IT, 2*p+1, mid+1, r, L, R);
        return max(res1, res2);
    }
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    sieve();
    scanf("%d %d %d", &m, &n, &q);
    int g[m + 2][n + 2];
    memset(g, 0, sizeof g);
    int f[n + 2][m + 2];
    int IT[n + 2][4*m + 2];

    int num;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &num);
            if (era[num] == 0) h[j] ++;
            else h[j] = 0;
        }
        stack<int> st;
        for (int j = 1; j <= n; j++) {
            while (!st.empty() && h[st.top()] >= h[j]) st.pop();
            if (st.empty()) l[j] = 0;
            else l[j] = st.top();
            st.push(j);
        }

        while (!st.empty()) st.pop();
        int tmp;

        for (int j = n; j >= 1; j--) {
            while (!st.empty() && h[st.top()] >= h[j]) st.pop();
            if (st.empty()) r[j] = n+1;
            else r[j] = st.top();
            st.push(j);

            tmp = r[j] - l[j] - 1;
            g[i][tmp] = max(g[i][tmp], h[j]);
        }
        tmp = 0;
        for (int j = n-1; j >= 1; j--) g[i][j] = max(g[i][j], g[i][j+1]);
    }

    //----------------------------------------------
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) f[i][j] = g[j][i];

    for (int i = 1; i <= n; i++) build(IT[i], f[i], 1, 1, m);

    //-------------------------------------------------
    int x, y, r, c;
    while (q--) {
        scanf("%d %d %d %d", &x, &y, &r, &c);
        x = x + r - 1;
        if (rmq(IT[c], 1, 1, m, x, y) >= r) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
/** Happy Coding ^^ */

