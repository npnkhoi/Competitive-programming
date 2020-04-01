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
const int N = 5e5 + 10;
int n, m, pre[N], nex[N], a[N];
vector<int> v;
int main() {
    freopen("LISTA.inp","r",stdin);
    freopen("LISTA.out","w",stdout);
    scanf("%d %d", &n, &m);
    FOR(i, 2, n) pre[i] = i-1; pre[1] = -1;
    FOR(i, 1, n-1) nex[i] = i+1; nex[n] = -1;
    char ch;
    int x, y;
    while (m--) {
        scanf(" %c %d %d", &ch, &x, &y);
        if (pre[x] != -1) nex[pre[x]] = nex[x];
        if (nex[x] != -1) pre[nex[x]] = pre[x];
        if (ch == 'A') {
            pre[x] = pre[y];
            if (pre[y] != -1) nex[pre[y]] = x;
            pre[y] = x; nex[x] = y;
        }
        else {
            nex[x] = nex[y];
            if (nex[y] != -1) pre[nex[y]] = x;
            nex[y] = x; pre[x] = y;
        }
    }
    FOR(i, 1, n) if (pre[i] == -1) a[1] = i;
    FOR(i, 2, n) a[i] = nex[a[i-1]];
    v.push_back(a[1]);
    FOR(i, 2, n) {
        if (a[i] > v.back()) v.push_back(a[i]);
        else {
            int pos = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[pos] = a[i];
        }
    }
    cout << n - v.size();
    return 0;
}
/** Happy Coding ^^ */
