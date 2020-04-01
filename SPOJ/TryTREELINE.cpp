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
#define REP(i ,n) for (int i = 0; i < n; i++;
const int N = 20;
const int oo = 1e9;
int a[N], vis[N], n;
void check() {
    int min1 = oo, min2 = oo;
    FOD(i, n, 1) {
        if (a[i] > min2) return;
        else if (a[i] > min1) min2 = min(min2, a[i]);
        else min1 = min(min1, a[i]);
    }
    FOR(i, 1, n) printf("%3d", a[i]); cout << endl;
}
void backTrack(int i) {
    if (i == n+1) check();
    else
    FOR(j, 1, n) if (vis[j] == 0) {
        a[i] = j; vis[j] = 1;
        backTrack(i+1);
        vis[j] = 0;
    }
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    backTrack(1);
    return 0;
}
/** Happy Coding ^^ */
