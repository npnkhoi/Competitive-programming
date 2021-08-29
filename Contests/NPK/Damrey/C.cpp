using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 105;
const int A = 30;

int n, a[N], pos[N], key[A];
string str[N];
vector<int> adj[A], topo;
int mark[A];
bool mat[A][A];



void makeEdge(string &a, string &b) {
    for (int i = 0; i < a.size() && i < b.size(); i++)
        if (a[i] != b[i]) {
            int u = a[i] - 'a';
            int v = b[i] - 'a';
            if (mat[u][v] == 0) {
                mat[u][v] = 1;
                adj[u].push_back(v);
            }
            //cout << a << " " << b << " " << a[i] - 'a' << " " << b[i] - 'a' << "\n";
            //degIn[b[i] - 'a'] ++;
            return;
        }
    if (a.size() > b.size()) {
        printf("NE");
        exit(0);
    }
}
void dfs(int u) {
    //printf("dfs %d\n", u);
    mark[u] = -1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        //printf("-> %d %d\n", v, mark[v]);
        if (mark[v] == -1) {
            printf("NE");
            exit(0);
        } else if (mark[v] == 0)
            dfs(v);
    }
    mark[u] = 1;
    topo.push_back(u);
    //printf("end %d\n", u);
}
void testCycle() {
    FOR(i, 0, 25) {
        dfs(i);
        memset(mark, 0, sizeof mark);
    }
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("C.inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d ", &n);
    FOR(i, 1, n) getline(cin, str[i]);
    //FOR(i, 1, n) cout << str[i] << "\n";
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    FOR(i, 1, n-1) FOR(j, i+1, n)
        makeEdge(str[a[i]], str[a[j]]);
    /*REP(i, 26) {
        printf("%d: ", i);
        REP(j, adj[i].size()) {
            int v = adj[i][j];
            printf("%d ", v);
        }
        cout << "\n";
    }*/

    testCycle();
    REP(i, 26) if (mark[i] == 0) dfs(i);
    reverse(topo.begin(), topo.end());
    printf("DA\n");
    REP(i, 26) {
        key[topo[i]] = i;
        //printf("%d " , topo[i]);
    }
    //cerr << "\n";
    REP(i, 26) printf("%c", key[i] + 'a');


    return 0;
}
/** Happy Coding :D */
