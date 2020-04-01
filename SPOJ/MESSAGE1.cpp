#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define taskName "message1"

const int N = 105;
char a[N][N], b[N][N];
int c[N][N], h[N];
int m, n, res;

int maxRec(int m, int n) { /// process on array c[][]
    memset(h, 0, sizeof h);
    int res = 0;
    FOR(i, 1, m) {
        FOR(j, 1, n) {
            if (c[i][j]) h[j] ++;
            else h[j] = 0;
        }
        stack<int> st;
        FOR(j, 1, n) {
            while (!st.empty() && h[st.top()] >= h[j]) st.pop();
            int tmp;
            if (st.empty()) tmp = 0;
            else tmp = st.top();
            res = max(res, h[j] * (j - tmp));
            st.push(j);
        }
    }
    return res;
}
void calc() {
    REP(x, m) REP(y, n) {
        int p = m - x;
        int q = n - y;
        int cnt = 0;
        FOR(i, 1, p) FOR(j, 1, q) {
            c[i][j] = (a[i][j+y] == b[i+x][j]);
            cnt += c[i][j];
        }
        //if (cnt > res)
        res = max(res, maxRec(p, q));
    }
    REP(x, m) REP(y, n) {
        int p = m - x;
        int q = n - y;
        int cnt = 0;
        FOR(i, 1, p) FOR(j, 1, q) {
            c[i][j] = (a[i-x][j-y] == b[i][j]);
            cnt += c[i][j];
        }
        //if (cnt > res)
        res = max(res, maxRec(p, q));
    }
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d%d", &m, &n);
        FOR(i, 1, m) FOR(j, 1, n) scanf(" %c", &a[i][j]);
        FOR(i, 1, m) FOR(j, 1, n) scanf(" %c", &b[i][j]);
        res = 0;
        calc();
        FOR(i, 1, m) FOR(j, 1, n) swap(a[i][j], b[i][j]);
        calc();
        printf("%d\n", res);
    }
    /*FOR(i, 2, 3) FOR(j, 2, 4) c[i][j] = 1;
    cerr << maxRec(3, 4) << "\n";*/
    return 0;
}
/** Happy Coding :D */
