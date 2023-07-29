#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++ i)

const int INF = 1e9, MY_INF = 1e4;
 
struct Edge {
    int a, b, cap, flow;
};

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;

    MaxFlow(int n) : n(n), d(n), ptr(n), q(n), g(n) {
        e.clear();
        REP(i,n) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap) {
        Edge e1 = { a, b, cap, 0 };
        Edge e2 = { b, a, 0, 0 };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            REP(i,n) ptr[i] = 0;
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }

private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        REP(i,n) d[i] = -1;
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            REP(i,g[v].size()) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};

int r, c;
vector<string> board;

const int N = 1e3 + 2;
int id_dot[N][N];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int get_id(int row, int col) {
    return row * c + col;
}

bool inBoard(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

int main() {
    //freopen("B.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    board.clear();
    for (int i = 0; i < r; ++ i) {
        string str; cin >> str;
        board.push_back(str);
    }
    if (board[0][0] == '#' || board[r - 1][c - 1] == '#') {
        cout << "0\n";
        return 0;
    }
    if (board[0][0] == '.' || board[r - 1][c - 1] == '.') {
        cout << "1\n";
        return 0;
    }


    int count_dots = 0;
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            if (board[i][j] == '.') {
                id_dot[i][j] = count_dots ++;
            }
        }
    }

    MaxFlow mf(r * c + count_dots);
    for (int i = 0; i < r; ++ i) {
        for (int j = 0; j < c; ++ j) {
            if (board[i][j] == '#') continue;
            if (board[i][j] == '.') {
                mf.addEdge(get_id(i, j), id_dot[i][j] + r * c, 1);
            }
            for (int dir = 0; dir < 4; ++ dir) {
                int u = dx[dir] + i, v = dy[dir] + j;
                if (!inBoard(u, v) || board[u][v] == '#') continue;
                int cap = 1;
                if (board[u][v] == '@') cap = MY_INF;

                // if (board[i][j] == '.') node1 += r * c;
                mf.addEdge((board[i][j] == '.' ? r * c + id_dot[i][j] : get_id(i, j)), get_id(u, v), cap);
            }
        }
    }
    int ans = mf.getMaxFlow(0, r * c - 1);
    cout << (ans >= MY_INF ? -1 : ans) << '\n';
}
