using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,b,a) for (int i = (b); i >= (a); --i)
#define REP(i,n) for (int i = 0; i < (n); ++i)

const int N = 105;
const int maxNode = 1e4 + 5;
const int maxChar = 28;
const int oo = 1e9 + 7;

int Next[maxNode][maxChar];
int End[maxNode];
int Inf[maxNode];

vector<int> pos[30];

int n, l;
int w[N], f[N];
int g[N][N][maxNode], memo[N][N], dp[N][N];

string str, s;
int c;
int cur = 0;

void initTrie()  {
    cur = 0;
    Inf[0] = -1;
    memset(Next, -1, sizeof Next);
    memset(Inf, -1, sizeof Inf);
    memset(End, -1, sizeof End);
}
void add(string &s, int c) {
    //cerr << "add " << s << endl;
    int tmp = 0;
    FORD(i, s.size() - 1, 0) {
        if (Next[tmp][s[i]-'a'] == -1) {
            tmp = Next[tmp][s[i]-'a'] = ++ cur;
            Inf[cur] = s[i] - 'a';
            //cerr << "cur = " << cur << "\n";
        }
        else tmp = Next[tmp][s[i] - 'a'];
        //cout << tmp << endl;
    }
    End[tmp] = max(End[tmp], c);
}
int start(int x, int L) {
    int l = 0, r = pos[x].size() - 1;
    int res = r;
    while (l <= r) {
        int mid = (l+r)/2;
        if (pos[x][mid] >= L)
            res = min(res, mid), r = mid - 1;
        else l = mid + 1;
    }
    if (pos[x][res] >= L) return res;
    return pos[x].size();
}
int finish(int x, int R) {
    int l = 0, r = pos[x].size() - 1;
    int res = l;
    while (l <= r) {
        int mid = (l+r)/2;
        if (pos[x][mid] <= R)
            res = max(res, mid), l = mid + 1;
        else r = mid - 1;
    }
    if (pos[x][res] <= R) return res;
    return -1;
}
int getG(int i, int j, int h) {
    if (i > j) return -oo;
    else if (i == j)
        if (End[h] > 0) return End[h];
        else return -oo;
    else return g[i][j][h];
}
int getDp(int i, int j) {
    if (i > j) return 0;
    else return dp[i][j];
}

int main() {
    freopen("WORD.inp", "r", stdin);
    freopen("WORD.out", "w", stdout);

    getline(cin, str); l = str.size();
    REP(i, l) pos[str[i]-'a'].pb(i);

    scanf("%d ", &n);
    initTrie();
    int duide = oo;
    FOR(i, 1, n) {
        getline(cin, s);

        scanf("%d ", &c);
        duide = min(duide, c);
        //cerr << i << endl;
        add(s, c);
        //cerr << i << endl;
    }
    //cerr << duide << endl;
    /*FOR(i, 0, cur) {
        FOR(j, 0, 3) printf("%5d", Next[i][j]);
        cerr << endl;
    }
    cerr << endl;
    FOR(i, 0, cur) cerr << End[i] << " ";
    cerr << endl;
    FOR(i, 0, cur) cerr << Inf[i] << " ";
    cerr << endl;
    REP(i, 26) {
        REP(j, pos[i].size()) cerr << pos[i][j] << " ";
        cerr << endl;
    }*/
    //----------------------------------------------
    REP(i, l) REP(j, l) FOR(h, 0, cur) g[i][j][h] = -oo;
    REP(i, l) REP(j, l) memo[i][j] = -oo;
    REP(i, l) REP(j, l) dp[i][j] = -oo;

    FORD(i, l-1, 0)
    FOR(j, i, l-1) {
        FORD(h, cur, 0) if (str[j]-'a' == Inf[h]) {
            //bool mark = 0;
            if (i < j)
            REP(k, 26) if (Next[h][k] != -1 && pos[k].size() > 0) {
                //mark = 1;
                int tmp = Next[h][k];
                //printf("ahihi %d %d %d\n", i, j, k);
                int l = start(k, i);
                //cout << "ok\n";
                //int r = finish(k, j-1);
                //printf("to (%d) %d: %d %d\n", tmp, k, l, r);
                for (int x = l; x < pos[k].size() && pos[k][x] < j; x++) {
                    int _j = pos[k][x];
                    //printf("*** %d\n", _j);
                    if (getG(i,_j, tmp) >= 0 && getDp(_j+1, j-1) >= 0)
                    g[i][j][h] = max(g[i][j][h], getG(i,_j, tmp) + getDp(_j+1, j-1));
                }
            }
            if (i == j && End[h] > 0) g[i][j][h] = End[h];
            //printf("dp %d %d %d = %d\n", i, j, h, g[i][j][h]);
        }
        REP(k, 26) if (Next[0][k] != -1)
            memo[i][j] = max(memo[i][j], g[i][j][Next[0][k]]);
        //printf("memo[%d][%d] = %d\n", i, j, memo[i][j]);
        dp[i][j] = memo[i][j];
        FOR(k, i+1, j) dp[i][j] = max(dp[i][j], getDp(i, k-1) + getDp(k, j));
        //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);

    }
    //----------------------------------------------
    f[0] = max(0, dp[0][0]);
    FOR(i, 0, l-1) {
        f[i] = max(f[i-1], dp[0][i]);
        FOR(j, 1, i) f[i] = max(f[i], f[j-1] + dp[j][i]);
    }
    cout << f[l-1];

    return 0;
}
/** Happy Coding ^^ */

