using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

const int N = 3e5 + 5;
int n, m, med, a[N];
ii b[N];
set<ii> set1, set2;
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MEDIAN.inp", "r", stdin);
    freopen("MEDIAN.out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d%d", &n, &m);
    med = n+1;
    n = n + n + 1;
    REP(i, n) {
        scanf("%d", &a[i]);
        b[i] = mp(a[i], i);
    }
    sort(b, b+n);
    FOR(i, 0, med-1) set1.insert(b[i]);
    FOR(i, med, n-1) set2.insert(b[i]);

    while (m--) {
        int i, k;
        scanf("%d%d", &i, &k);
        if (set1.count(mp(a[i], i))) {
            set1.erase(mp(a[i], i));
            set2.insert(mp(k, i));
            ii tmp = *set2.begin();
            set2.erase(set2.begin());
            set1.insert(tmp);
        } else {
            set2.erase(mp(a[i], i));
            set1.insert(mp(k, i));
            ii tmp = *set1.rbegin();
            set1.erase(tmp);
            set2.insert(tmp);
        }
        a[i] = k;

        printf("%d\n", (*set1.rbegin()).fi);
    }

    return 0;
}
/** Happy Coding :D */
