#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 11, MASK = (1 << 9) + 5, CON = (1 << 5);

// dp[row] = map of {(mask, con): val}
// con: a bitmask of size 10, acts as adj matrix + whether some cells have been chosen
map<pair<int, int>, int> dp[N];
int n, m, a[N][M], dsu[2 * M];
bool adj[5][5], index;

void join(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u == v) return;
    // u must be the larger tree
    if (root[u] > root[v]) swap(u, v);
    root[v] = u;
    root[u] -= 1;
}

int getRoot(int u) {
    if (root[u] < 0) return u;
    else {
        root[u] = getRoot(root[u]);
        return root[u];
    }
}

bool getBit(int mask, int pos) {
    return ((mask >> pos) & 1);
}

void parseCon(int con) {
    // Side effect: update adj[] and picked (global vars)
    int index = 0;
    for (int i = 0; i < 4; ++ i) {
        for (int j = i + 1; j < 5; ++ j) {
            adj[i][j] = ((con >> index) & 1);
            index ++;
        }
    }
    picked = ((con >> index) & 1);
}

int newCon(int mask, int con, int newMask) {
    // return -1 if invalid
    // else return newCon

    // first row: 0 -> m-1; second row: m -> 2m-1
    bool inComp = false;
    int cntComp = 0;
    memset(headOfComp, -1, sizeof headOfComp);
    memset(root, -1, sizeof root);

    for (int i = 0; i < m; ++i) {
        if (getBit(mask, i)) {
            if (inComp) {
                join(i-1, i);
            } else {
                inComp = true;
                headOfComp[cntComp] = i;
                cntComp ++;
            }
        }
    }
    parseCon(con);
    for (int i = 0; i < cntComp; i++) {
        for (int j = i + 1; j < cntComp; j++) {
            if (adj[i][j]) join(headOfComp[i], headOfComp[j]);
        }
    }

    inComp = false;
    int newCntComp = 0;
    memset(newHeadOfComp, -1, sizeof newHeadOfComp);

    // init leftBehind
    for (int i = 0; i < m; ++ i) leftBehind[i] = true;

    for (int i = 0; i < m; ++ i) {
        if (getBit(newMask, i)) {
            if (getBit(mask, i)) {
                join(i, m+i);
                leftBehind[getRoot(i)] = false;
            }
            if (inComp) {
                join(m+i-1, m+i);
            } else {
                inComp = true;
                newHeadOfComp[cntComp] = i;
                newCntComp ++;
            }
        }
    }

    // check if any comp is left behind
    for (int i = 0; i < cntComp; ++i) {
        int r = getRoot(headOfComp[i]);
        if (leftBehind[r]) return -1;
    }

    // return new con
    int index = 0, ret = 0;
    for (int i = 0; i < 4; ++ i) {
        for (int j = i + 1; j < 5; ++ j) {

            ret |= ((getRoot(headOfComp[i]) == getRoot(headOfComp[j])) << index);
            index ++;
        }
    }
    bool newPicked = picked || (newMask != 0);
    ret |= (pick << index);
    return ret;
}

bool connected(int mask, int con) {
    parseCon(con);

    // below is copied
    bool inComp = false;
    int cntComp = 0;
    memset(headOfComp, -1, sizeof headOfComp);
    memset(root, -1, sizeof root);

    for (int i = 0; i < m; ++i) {
        if (getBit(mask, i)) {
            if (inComp) {
                join(i-1, i);
            } else {
                inComp = true;
                headOfComp[cntComp] = i;
                cntComp ++;
            }
        }
    }
    parseCon(con);
    for (int i = 0; i < cntComp; i++) {
        for (int j = i + 1; j < cntComp; j++) {
            if (adj[i][j]) join(headOfComp[i], headOfComp[j]);
        }
    }
    if ()
}

int main() {
    freopen("test.inp", "r", stdin);

    int tc;
    cin >> tc;
    dp[0][{0, 0}] = 0;
    while (tc --) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++ i) {
            dp[i].clear();

            for (int j = 1; j <= m; ++ j) {
                cin >> a[i][j];
            }

            // transition from row i-1 to i
            for (auto pack : dp[i-1]) {
                int mask = pack.first.first;
                int con = pack.first.second;
                int val = pack.second;

                for (int newMask = 0; newMask < (1 << m); newMask ++) {
                    int sumRow = 0;
                    for (int j = 0; j < m; ++ j) {
                        if ((newMask >> j) & 1) {
                            sumRow += a[i][j + 1];
                        }
                    }
                    int newCon = connect(mask, con, newMask);
                    if (newCon == -1) continue;
                    dp[i][{newMask, newCon}] = val + sumRow;
                }
            }
        }

        // get result
        int res = 0;
        for (auto pack : dp[n]) {
            int mask = pack.first.first;
            int con = pack.first.second;
            int val = pack.second;

            if (connected(mask, con)) {
                res = max(res, val);
            }
        }
        cout << res << '\n';
    }
}


    /*
    int cntComp = 0, inComp = false;
    memset(comp, 0, sizeof comp); // comp[i] = one-based id of the component the cell is in
    for (int i = 0; i < m; ++ i) {
        if (getBit(mask, i)) {
            if (!inComp) {
                inComp = true;
                cntComp ++;
            }
            comp[i] = cntComp;

        }
    }
    */
