#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "mooyomooyo"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105, M = 15, CELL = 1005;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, k, idx;
char a[N][M];
int id[N][M], cnt[CELL];
queue<ii> q;

void input() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n) FOR(j, 1, 10) {
        cin >> a[i][j];
        a[i][j] -= '0';
    }
}

bool inBoard(int u, int v) {
    return 1 <= u && u <= n && 1 <= v && v <= 10;
}

void bfs(int x, int y) {
    int color = a[x][y];
    ++ idx;
    cnt[idx] = 1;
    id[x][y] = idx;
    q.push(mp(x, y));
    while (!q.empty()) {
        ii t = q.front();
        q.pop();
        REP(i, 4) {
            int u = t.fi + dx[i];
            int v = t.se + dy[i];
            if (!inBoard(u, v) || id[u][v] || a[u][v] != color) continue;
            cnt[idx] ++;
            id[u][v] = idx;
            q.push(mp(u, v));
        }
    }
}

void solve() {
    while (1) {
        memset(id, 0, sizeof id);
        idx = 0;
        bool flag = 0;
        FOR(i, 1, n) FOR(j, 1, 10){
            if (a[i][j] == 0 || id[i][j]) continue;
            bfs(i, j);
            if (cnt[idx] >= k) flag = 1;
        }
        if (!flag) break;

        FOR(j, 1, 10) {
            int top = n + 1;
            FORD(i, n, 1) {
                if (a[i][j] == 0) break;
                if (cnt[id[i][j]] < k) {
                    a[--top][j] = a[i][j];
                }
            }
            FOR(i, 1, top-1) a[i][j] = 0;
        }
        /*FOR(i, 1, n) {
            FOR(j, 1, 10) cout << (int)a[i][j];
            cout << '\n';
        }
        cout << '\n';*/
    }
}

void output() {
    FOR(i, 1, n) {
        FOR(j, 1, 10) cout << (int)a[i][j];
        cout << '\n';
    }
}

int main() {
	input();
    solve();
    output();
}
