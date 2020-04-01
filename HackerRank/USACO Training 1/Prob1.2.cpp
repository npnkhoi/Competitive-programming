using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 5e4 + 5;
int n, x[N], l[N], r[N];
double res;
bool okLeft(int pos, int R) {
    if (pos == 1) return true;
    int l = 1, r = pos;
    while (l < r) {
        int mid = (l + r) / 2;
        if (x[pos] - x[mid] <= R) r = mid;
        else l = mid + 1;
    }
    if (l == pos) return false;
    else return okLeft(l, R-1);
}
int ansLeft(int t) {
    //printf("ansLeft %d\n", t);
    int l = 1, r = n;
    while (l < r) {
        //cout << l << " " << r << endl;
        int mid = (l + r + 1) / 2;
        if (okLeft(mid, t)) l = mid;
        else r = mid - 1;
    }
    return l;
}
bool okRight(int pos, int R) {
    if (pos == n) return true;
    int l = pos, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (x[mid] - x[pos] <= R) l = mid;
        else r = mid - 1;
    }
    if (l == pos) return false;
    else return okRight(l, R-1);
}
int ansRight(int t) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (okRight(mid, t)) r = mid;
        else l = mid + 1;
    }
    return l;
}
bool ok(int t) {
    int a = ansLeft(t/2-1);
    int b = ansRight(t/2-1);
    if (a >= b) return true;
    else return x[b] - x[a] <= t;
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &x[i]);
    sort(x+1, x+m+1);
    n = 1;
    for (int i = 2; i <= m; i++) if (x[i] != x[i-1]) x[++n] = x[i];
    if (n == 1) { printf("1.0"); return 0; }

    int l = 1, r = 2*(1 + x[n] - x[1]);
    while (l < r) {
        int mi = (l + r) / 2;
        if (ok(mi)) r = mi;
        else l = mi + 1;
    }
    /*cout << "------\n";
    cout << okLeft(2, 3) << endl;
    cout << okLeft(1, 3) << endl;
    cout << okLeft(3, 3) << endl;
    cout << ansLeft(3) << endl;*/
    printf("%d.%d", l/2, l%2*5);

    return 0;
}
/** Happy Coding ^^ */

