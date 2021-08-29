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
int n;
bool res = 1;
bool isNull(int u) {
    return (u > n || a[u] == 0);
}
bool isLeaf(int u) {
    return isNull(2*u) && isNull(2*u+1);
}
void dfs(int u) {
    if (u > n || a[u] == 0) return;
    dfs(2*u); dfs(2*u+1);
    if (!isLeaf(u)) {
        int s = 0;
        if (!isNull(2*u)) s += a[2*u];
        if (!isNull(2*u+1)) s += a[2*u+1];
        if (s != a[u]) res = 0;
        a[u] += s;
    }
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    int num;
    while (scanf("%d", &num) != EOF) a[++n] = num;
    dfs(1);
    if (res) printf("Yes");
    else printf("No");
    return 0;
}
/** Happy Coding ^^ */
