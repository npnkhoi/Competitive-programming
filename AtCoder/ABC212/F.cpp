#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LOG = 20;

vector<int> adj[N], times[N];
int anc[LOG][N], numNodes = 0;
bool isRoot[N];
pair<int, int> idToData[2*N];
map<pair<int, int>, int> dataToId;

int id(int city, int time) {
    pair<int, int> data = {city, time};
    if (dataToId.find(data) == dataToId.end()) {
        idToData[numNodes] = data;
        dataToId[data] = numNodes ++;
    }
    cerr << "id of " << city << ' ' << time << " => " << dataToId[data] << '\n';
    return dataToId[data];
}

void connect(int a, int b) {
    // adj[b].push_back(a);
    anc[a][0] = b;
    isRoot[a] = false;
    cerr << "connecting " << a << ' ' << b << '\n';
}

int main() {
    freopen("F.inp", "r", stdin);
    memset(anc, -1, sizeof anc);
    
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++ i) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        s = s * 2 + 1;
        t = t * 2 + 1;
        
        connect(id(a, s), id(b, t));
        times[a].push_back(s);
        times[b].push_back(t);
    }
    for (int i = 1; i <= n; ++i) {
        sort(times[i].begin(), times[i].end());
        for (int j = 1; j < times[i].size(); ++ j) {
            if (times[i][j-1] == times[i][j]) {
                continue;
            }
            cerr << "Connecting inside city " << i << '\n';
            connect(id(i, times[i][j-1]), id(i, times[i][j]));
        }
    }

    // Prepare the parse table
    // for (int v = 0; v < numNodes; ++ v) {
    //     if (isRoot[v]) {
    //         dfs(v); // to know the depth ??
    //     }
    // }

    for (int d = 1; d < LOG; ++ d) {
        for (int v = 0; v < numNodes; ++ v) {
            if (anc[v][d-1] != -1) {
                anc[v][d] = anc[anc[v][d-1]][d-1];
                printf("anc[%d][%d] = %d\n", v, d, anc[v][d]);
            }
        }
    }

    // Answer the queries
    while (q--) {
        cerr << "Stating query ----\n";
        int x, y, z;
        cin >> x >> y >> z;
        x *= 2;
        z *= 2;

        int pos = upper_bound(times[y].begin(), times[y].end(), x - 1) - times[y].begin();
        cerr << pos << '\n';
        if (pos == times[y].size()) {
            // stand here forever
            cout << y << '\n';
            continue;
        }
        int v = id(y, times[y][pos]);
        cerr << "starting node: " << v << '\n';
        pair<int, int> dataNearest = {y, x};
        for (int d = LOG-1; d >= 0; --d) {
            int tmp = anc[v][d];
            if (tmp == -1) {
                continue;
            }
            pair<int, int> data = idToData[tmp];
            if (data.second <= z) {
                v = tmp;
                dataNearest = data;
                printf("jump to %d\n", v);
            }
        }
        printf("nearest time: %d\n", dataNearest.second);
        if (dataNearest.second == z) {
            cout << dataNearest.first << '\n';
        } else if (*times[dataNearest.first].rbegin() > dataNearest.second) {
            cout << dataNearest.first << '\n';
        } else {
            pair<int, int> dataNext = idToData[anc[v][0]];
            cout << dataNearest.first << ' ' << dataNext.first << '\n';
        }
    }
}