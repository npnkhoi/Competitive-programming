#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2000 + 5;
int n, m, a[N][N], cnt[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d %d", &n, &m);
    FOR(i, 1, n) FOR(j, 1, m) {
        char ch;
        scanf(" %c", &ch);
        a[i][j] = ch - '0';
        cnt[j] += a[i][j];
    }
    /*FOR(i, 1, n) {
        FOR(j, 1, m) cerr << a[i][j] << " ";
        cerr << "\n";
    }*/
    FOR(i, 1, n) {
        bool ok = true;
        FOR(j, 1, m) if (cnt[j] - a[i][j] <= 0) ok = false;
        if (ok) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}
