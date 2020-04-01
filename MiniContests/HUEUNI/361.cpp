using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
int a[105];
int n, nodes, leaves, h, _min, _max, num;
bool isNull(int u) {
    return (u > n || a[u] == 0);
}
void dfs(int u, int cur) {
    if (u > n || a[u] == 0) return;
    nodes ++;
    if (isNull(2*u) && isNull(2*u+1)) leaves ++;
    h = max(h, cur);
    _min = min(_min, a[u]);
    _max = max(_max, a[u]);
    dfs(2*u, cur + 1); dfs(2*u+1, cur + 1);
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    while (scanf("%d", &num) != EOF) a[++n] = num;
    _min = a[1];
    dfs(1, 0);
    printf("%d\n", nodes);
    printf("%d\n", leaves);
    printf("%d\n", h);
    printf("%d %d", _max, _min);
    return 0;
}
/** Happy Coding ^^ */
