#include <bits/stdc++.h>
using namespace std;
// #define int long long

typedef pair<int, int> pii;
const int M = 31;
const int N = M*M + 5;

int m, degIn[N];
long long n, res[5], dp[N];
// priority_queue<pii> pq;
queue<pii> q;
vector<int> adj[N], cand[N];

int getLog2(int n) {
    // cerr << n << '\n';
    if (n == 1LL) return 0;
    return 1 + getLog2(n / 2);
}

int getId(int i, int j) {
    return i * (m+1) + j;
}

void addEdge(int u, int v) {
    /// context, from state u, the game can go to state v
    /// so when dp, we reserve that
    adj[v].push_back(u); /// may change the order?
    degIn[u] ++;
    /// update deg?
}

void addEdges(int i, int j) {
    /// i and j are two exps, the i is to be divided
    int id = i * (m+1) + j;
    if (i > 0) {
        if (i < j + 1) addEdge(id, getId(i - 1, i - 1));
        else if (i > j + 1) addEdge(id, getId(i-1, j));
        else addEdge(id, getId(i-1, i));
    }
    if (j > 0) {
        if (j < i + 1) addEdge(id, getId(j - 1, j - 1));
        else if (j > i + 1) addEdge(id, getId(i, j-1));
        else addEdge(id, getId(j, j-1));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Your efficient code here
    cin >> n;
    m = getLog2(n) + 1;
    // cerr << "m: " << m << '\n';

    for (int i = 0; i <= m; ++ i) {
        for (int j = 0; j <= m; ++ j) {
            dp[getId(i, j)] = -2;
            addEdges(i, j);
        }
    }

    q.push({-1, getId(0, 0)});
    dp[getId(0, 0)] = -1;

    for (int i = 1; i <= m; ++ i) {
        q.push({0, getId(0, i)});
        q.push({0, getId(i, 0)});
        dp[getId(0, i)] = 0;
        dp[getId(i, 0)] = 0;
    }

    // cerr << "ok\n";

    while (!q.empty()) {
        pii tmp = q.front(); q.pop();
        int vertex = tmp.second;
        int val = tmp.first;
        for (int v : adj[vertex]) {
            if (dp[v] != -2) continue;

            cand[v].push_back(-val);

            if (val == -1) {
                dp[v] = -val;
                q.push({dp[v], v});
            } else if (cand[v].size() == degIn[v]) {
                int best = -1;
                for (int t : cand[v]) {
                    best = max(best, t);
                }

                dp[v] = best;
                q.push({best, v});
            }
        }
    }

    for (int i = 0; i <= m; ++ i) {
        for (int j = 0; j <= m; ++ j) {
            int typ = ((dp[getId(i, j)] == -2) ? 0 : dp[getId(i, j)]);
            res[typ + 1] += ((n / (1LL << i) + 1) / 2) * ((n / (1LL << j) + 1) / 2);

            // cerr << dp[getId(i, j)] << ' ';
        }
        // cerr << '\n';
    }
    for (int i = 2; i >= 0; -- i) {
        cout << res[i] << '\n';
    }
}
