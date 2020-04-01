#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <string>
#include <functional>
#include <bitset>
#include <complex>
#include <iterator>
/// y0 y1 y1 j1 lr tm next prev link norm
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define task ""
typedef long long ll;
typedef pair<int, int> ii;

const int N = 205;
int n, m;
int start, s, minS;
int a[N][N], deg[N];
bool link[N][N], mark[N];
vector<int> tour;
stack<int> st;
queue<int> q;

void bfs() {
    q.push(1); mark[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        FOR(v, 1, n) if (link[u][v] && !mark[v]) {
            mark[v] = 1;
            q.push(v);
        }
    }
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        link[u][v] = link[v][u] = 1;
        a[u][v] = a[v][u] = c;
        deg[u] ++; deg[v] ++;
    }
    bfs();
    FOR(i, 1, n) if (!mark[i] || deg[i]%2) {
        printf("-1");
        //cerr << i << "\n";
        exit(0);
    }

    st.push(1);
    while (!st.empty()) {
        int u = st.top();
        FOR(v, 1, n) if (link[u][v]) {
            link[u][v] = link[v][u] = 0;
            st.push(v);
            break;
        }
        if (st.top() == u) {
            tour.push_back(u);
            st.pop();
        }
    }
    //REP(i, tour.size()) cerr << tour[i] << "\n";
    FOR(i, 1, tour.size() - 1) {
        s += a[tour[i-1]][tour[i]];
        if (minS > s) {
            minS = s;
            start = i;
        }
    }
    if (s < 0) printf("-1");
    else {
        tour.pop_back();
        FOR(i, start, tour.size() - 1) printf("%d ", tour[i]);
        FOR(i, 0, start) printf("%d ", tour[i]);
    }

}
